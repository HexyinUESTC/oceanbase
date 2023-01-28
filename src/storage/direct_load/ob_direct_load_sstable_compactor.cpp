// Copyright (c) 2022-present Oceanbase Inc. All Rights Reserved.
// Author:
//   yiren.ly <yiren.ly@oceanbase.com>

#define USING_LOG_PREFIX STORAGE

#include "storage/direct_load/ob_direct_load_sstable_compactor.h"

namespace oceanbase
{
namespace storage
{
using namespace common;
using namespace blocksstable;

/**
 * ObDirectLoadSSTableCompactParam
 */

ObDirectLoadSSTableCompactParam::ObDirectLoadSSTableCompactParam()
  : datum_utils_(nullptr)
{
}

ObDirectLoadSSTableCompactParam::~ObDirectLoadSSTableCompactParam()
{
}

bool ObDirectLoadSSTableCompactParam::is_valid() const
{
  return tablet_id_.is_valid() && table_data_desc_.is_valid() && nullptr != datum_utils_;
}

/**
 * ObDirectLoadSSTableCompactor
 */

ObDirectLoadSSTableCompactor::ObDirectLoadSSTableCompactor()
  : index_item_count_(0), index_block_count_(0), row_count_(0), is_inited_(false)
{
}

ObDirectLoadSSTableCompactor::~ObDirectLoadSSTableCompactor()
{
}

int ObDirectLoadSSTableCompactor::init(const ObDirectLoadSSTableCompactParam &param)
{
  int ret = OB_SUCCESS;
  if (IS_INIT) {
    ret = OB_INIT_TWICE;
    LOG_WARN("ObDirectLoadSSTableCompactor init twice", KR(ret), KP(this));
  } else if (OB_UNLIKELY(!param.is_valid())) {
    ret = OB_INVALID_ARGUMENT;
    LOG_WARN("invalid args", KR(ret), K(param));
  } else {
    param_ = param;
    start_key_.set_min_rowkey();
    end_key_.set_min_rowkey();
    is_inited_ = true;
  }
  return ret;
}

int ObDirectLoadSSTableCompactor::add_table(ObIDirectLoadPartitionTable *table)
{
  int ret = OB_SUCCESS;
  if (IS_NOT_INIT) {
    ret = OB_NOT_INIT;
    LOG_WARN("ObDirectLoadSSTableCompactor not init", KR(ret), KP(this));
  } else {
    int cmp_ret = 0;
    ObDirectLoadSSTable *sstable = dynamic_cast<ObDirectLoadSSTable *>(table);
    if (OB_ISNULL(sstable)) {
      ret = OB_INVALID_ARGUMENT;
      LOG_WARN("invalid args", KR(ret), KP(sstable));
    } else if (OB_FAIL(check_table_compactable(sstable))) {
      LOG_WARN("fail to check table compactable", KR(ret), KPC(sstable));
    } else if (!sstable->is_empty()) {
      const ObDirectLoadSSTableMeta &table_meta = sstable->get_meta();
      index_item_count_ += table_meta.index_item_count_;
      index_block_count_ += table_meta.index_block_count_;
      row_count_ += table_meta.row_count_;
      for (int64_t i = 0; OB_SUCC(ret) && i < sstable->get_fragment_array().count(); ++i) {
        if (OB_FAIL(fragments_.push_back(sstable->get_fragment_array().at(i)))) {
          LOG_WARN("fail to push back table fragment", KR(ret), K(i));
        }
      }
      if (OB_SUCC(ret)) {
        end_key_allocator_.reuse();
        if (start_key_.is_min_rowkey() &&
            OB_FAIL(sstable->get_start_key().deep_copy(start_key_, start_key_allocator_))) {
          LOG_WARN("fail to deep copy start key", KR(ret));
        } else if (OB_FAIL(sstable->get_end_key().deep_copy(end_key_, end_key_allocator_))) {
          LOG_WARN("fail to deep copy end key", KR(ret));
        }
      }
    }
  }
  return ret;
}

int ObDirectLoadSSTableCompactor::check_table_compactable(ObDirectLoadSSTable *sstable)
{
  int ret = OB_SUCCESS;
  if (OB_UNLIKELY(nullptr == sstable || !sstable->is_valid())) {
    ret = OB_INVALID_ARGUMENT;
    LOG_WARN("invalid args", KR(ret), KPC(sstable));
  } else {
    const ObDirectLoadSSTableMeta &table_meta = sstable->get_meta();
    if (OB_UNLIKELY(
          table_meta.tablet_id_ != param_.tablet_id_ ||
          table_meta.rowkey_column_count_ != param_.table_data_desc_.rowkey_column_num_ ||
          table_meta.column_count_ != param_.table_data_desc_.column_count_ ||
          table_meta.index_block_size_ != param_.table_data_desc_.sstable_index_block_size_ ||
          table_meta.data_block_size_ != param_.table_data_desc_.sstable_data_block_size_)) {
      ret = OB_ITEM_NOT_MATCH;
      LOG_WARN("table meta not match", KR(ret), K(param_), K(table_meta));
    } else if (!sstable->is_empty()) {
      int cmp_ret = 0;
      if (OB_FAIL(end_key_.compare(sstable->get_start_key(), *param_.datum_utils_, cmp_ret))) {
        LOG_WARN("fail to compare rowkey", KR(ret));
      } else if (cmp_ret >= 0) {
        ret = OB_ROWKEY_ORDER_ERROR;
        LOG_WARN("sstable is not contiguous", KR(ret), K(end_key_), K(sstable->get_start_key()));
      }
    }
  }
  return ret;
}

int ObDirectLoadSSTableCompactor::compact()
{
  int ret = OB_SUCCESS;
  if (IS_NOT_INIT) {
    ret = OB_NOT_INIT;
    LOG_WARN("ObDirectLoadSSTableCompactor not init", KR(ret), KP(this));
  } else {
    // do nothing
  }
  return ret;
}

int ObDirectLoadSSTableCompactor::get_table(ObIDirectLoadPartitionTable *&table,
                                                  ObIAllocator &allocator)
{
  int ret = OB_SUCCESS;
  if (IS_NOT_INIT) {
    ret = OB_NOT_INIT;
    LOG_WARN("ObDirectLoadSSTableCompactor not init", KR(ret), KP(this));
  } else {
    ObDirectLoadSSTable *sstable = nullptr;
    ObDirectLoadSSTableCreateParam create_param;
    create_param.tablet_id_ = param_.tablet_id_;
    create_param.rowkey_column_count_ = param_.table_data_desc_.rowkey_column_num_;
    create_param.column_count_ = param_.table_data_desc_.column_count_;
    create_param.index_block_size_ = param_.table_data_desc_.sstable_index_block_size_;
    create_param.data_block_size_ = param_.table_data_desc_.sstable_data_block_size_;
    create_param.index_item_count_ = index_item_count_;
    create_param.index_block_count_ = index_block_count_;
    create_param.row_count_ = row_count_;
    create_param.start_key_ = start_key_;
    create_param.end_key_ = end_key_;
    if (OB_FAIL(create_param.fragments_.assign(fragments_))) {
      LOG_WARN("fail to assign fragments", KR(ret));
    } else if (OB_ISNULL(sstable = OB_NEWx(ObDirectLoadSSTable, (&allocator)))) {
      ret = OB_ALLOCATE_MEMORY_FAILED;
      LOG_WARN("fail to new ObDirectLoadSSTable", KR(ret));
    } else if (OB_FAIL(sstable->init(create_param))) {
      LOG_WARN("fail to init sstable table", KR(ret));
    } else {
      table = sstable;
    }
    if (OB_FAIL(ret)) {
      if (nullptr != sstable) {
        sstable->~ObDirectLoadSSTable();
        allocator.free(sstable);
        sstable = nullptr;
      }
    }
  }
  return ret;
}

void ObDirectLoadSSTableCompactor::stop()
{
}

} // namespace storage
} // namespace oceanbase
