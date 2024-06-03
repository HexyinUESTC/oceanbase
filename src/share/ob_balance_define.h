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

#ifndef OCEANBASE_SHARE_OB_BALANCE_DEFINE_H_
#define OCEANBASE_SHARE_OB_BALANCE_DEFINE_H_

#include "share/ob_common_id.h"             // ObCommonID
#include "share/schema/ob_table_schema.h"   // ObSimpleTableSchemaV2

namespace oceanbase
{
namespace share
{
typedef ObCommonID ObBalanceJobID;
typedef ObCommonID ObBalanceTaskID;
typedef ObCommonID ObTransferTaskID;
typedef ObCommonID ObTransferPartitionTaskID;

// check Tables that need balance by RS
//
// 1. USER TABLE: user created table, need balance
// 2. GLOBAL INDEX: global index is distributed independently from the main table, need balance
// 3. TMP TABLE: temp table is created by user, need balance
bool need_balance_table(const schema::ObSimpleTableSchemaV2 &table_schema);
bool check_if_need_balance_table(
    const schema::ObSimpleTableSchemaV2 &table_schema,
    const char *&table_type_str);

class ObBalanceStrategy
{
public:
  enum STRATEGY {
    // LS Balance
    LB_MIGRATE = 0,
    LB_ALTER = 1,
    LB_EXPAND = 2,
    LB_SHRINK = 3,
    // Manual Transfer
    MANUAL_TRANSFER = 4,
    // Partition Balance
    PB_COMPAT_OLD = 5, // for compatibility
    PB_ATTR_ALIGN = 6,
    PB_INTRA_GROUP = 7,
    PB_INTER_GROUP = 8,
    PB_PART_DISK = 9,
    MAX_STRATEGY
  };
  static const char* BALANCE_STRATEGY_STR_ARRAY[MAX_STRATEGY];
public:
  ObBalanceStrategy() : val_(MAX_STRATEGY) {}
  explicit ObBalanceStrategy(const STRATEGY &val) : val_(val) {}
  ~ObBalanceStrategy() {}
  void reset() { val_ = MAX_STRATEGY; }
  bool is_valid() const { return val_ >= LB_MIGRATE && val_ < MAX_STRATEGY; }
  bool is_partition_balance_strategy() const { return val_ >= PB_COMPAT_OLD && val_ <= PB_PART_DISK; }
  bool is_ls_balance_by_migrate() const { return LB_MIGRATE == val_; }
  bool is_ls_balance_by_alter() const { return LB_ALTER == val_; }
  bool is_ls_balance_by_expand() const { return LB_EXPAND == val_; }
  bool is_ls_balance_by_shrink() const { return LB_SHRINK == val_; }
  bool is_partition_balance_compatible_strategy() const { return PB_COMPAT_OLD == val_; }

  bool can_be_next_partition_balance_strategy(const ObBalanceStrategy &old_strategy) const;
  ObBalanceStrategy &operator=(const STRATEGY &val);
  bool operator==(const ObBalanceStrategy &other) const { return val_ == other.val_; }
  const char *str() const;
  int parse_from_str(const ObString &str);
  TO_STRING_KV(K_(val), "val", str());
private:
  STRATEGY val_;
};

} // end namespace share
} // end namespace oceanbase

#endif /* !OCEANBASE_SHARE_OB_BALANCE_DEFINE_H_ */
