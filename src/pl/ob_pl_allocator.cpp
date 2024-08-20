/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#define USING_LOG_PREFIX PL

#include "ob_pl_allocator.h"
#include "ob_pl_package_state.h"

namespace oceanbase
{
namespace pl
{

PlMemEntifyDestroyGuard::~PlMemEntifyDestroyGuard()
{
  int ret = 0;
  if (nullptr != ref_) {
    DESTROY_CONTEXT(ref_);
    ref_ = nullptr;
  }
}

int ObPLAllocator1::init(ObIAllocator *alloc)
{
  int ret = OB_SUCCESS;

  CK (OB_NOT_NULL(parent_allocator_));
  if (OB_SUCC(ret)) {
    if (OB_NOT_NULL(alloc)) {
      allocator_ = alloc;
    } else {
      allocator_ = reinterpret_cast<ObVSliceAlloc *>(parent_allocator_->alloc(sizeof(ObVSliceAlloc)));
      if (OB_ISNULL(allocator_)) {
        ret = OB_ALLOCATE_MEMORY_FAILED;
        LOG_WARN("fail to alloc memory for allocator", K(ret));
      } else {
        new(allocator_)ObVSliceAlloc(memattr_, 2 * 1024, alloc_mgr_);
      }
    }
    OX (is_inited_ = true);
  }

  return ret;
}


void* ObPLAllocator1::alloc(const int64_t size, const ObMemAttr &attr)
{
  int ret = OB_SUCCESS;
  void *ptr = NULL;
  if (!is_inited_ || OB_ISNULL(allocator_)) {
    ret = OB_ERR_UNEXPECTED;
    LOG_ERROR("must be init ObPLAllocator1, before using it to alloc", K(ret));
  } else {
    ret = OB_E(EventTable::EN_4) OB_SUCCESS;
    if (OB_UNLIKELY(OB_FAIL(ret))) {
      // do nothing
    } else {
      int64_t use_ob_malloc = -EVENT_CALL(EventTable::EN_PL_MEMORY_ALLOCA_SWITCH);
      if (use_ob_malloc > 0) {
        ptr = ob_malloc(size, attr);
      } else {
        ptr = allocator_->alloc(size, attr);
        int64_t addr = int64_t(ptr);
        //LOG_ERROR("===henry:alloc ptr===", K(addr));
      }
    }
  }
  return ptr;
}

void* ObPLAllocator1::realloc(const void *ptr, const int64_t size, const ObMemAttr &attr)
{
  int ret = OB_SUCCESS;
  void *newptr = NULL;
  if (!is_inited_ || OB_ISNULL(allocator_)) {
    ret = OB_ERR_UNEXPECTED;
    LOG_ERROR("must be init ObPLAllocator1, before using it to alloc", K(ret));
  } else {
    ret = OB_E(EventTable::EN_4) OB_SUCCESS;
    if (OB_UNLIKELY(OB_FAIL(ret))) {
      // do nothing
    } else {
      int64_t use_ob_malloc = -EVENT_CALL(EventTable::EN_PL_MEMORY_ALLOCA_SWITCH);
      if (use_ob_malloc > 0) {
        newptr = ob_realloc(const_cast<void *>(ptr), size, attr);
      } else {
        newptr = allocator_->realloc(ptr, size, attr);
      }
    }
  }
  return newptr;
}

void ObPLAllocator1::free(void *ptr)
{
  int ret = OB_SUCCESS;
  int64_t addr = int64_t(ptr);
  //LOG_ERROR("===henry:free ptr===", K(addr));
  if (!is_inited_ || OB_ISNULL(allocator_)) {
    ret = OB_ERR_UNEXPECTED;
    LOG_ERROR("must be init ObPLAllocator1, before using it to free", K(ret));
  } else {
    int64_t use_ob_malloc = -EVENT_CALL(EventTable::EN_PL_MEMORY_ALLOCA_SWITCH);
    if (use_ob_malloc > 0) {
      ob_free(ptr);
    } else {
      allocator_->free(ptr);
    }
  }
}

void ObPLAllocator1::reset()
{
  int ret = OB_SUCCESS;
  if (!is_inited_ || OB_ISNULL(allocator_)) {
    ret = OB_ERR_UNEXPECTED;
    LOG_ERROR("must be init ObPLAllocator1, before using it to reset");
  } else {
    //allocator_->reset();
  }
}

void ObPLAllocator1::destroy()
{
  if (is_inited_) {
    if (allocator_ != parent_allocator_) {
      static_cast<ObVSliceAlloc *>(allocator_)->~ObVSliceAlloc();
      parent_allocator_->free(allocator_);
      allocator_ = nullptr;
    }
    is_inited_ = false;
  }
}

}
}
