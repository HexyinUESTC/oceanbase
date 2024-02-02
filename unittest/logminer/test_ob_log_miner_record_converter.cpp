/**
 * Copyright (c) 2023 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#include "ob_log_miner_test_utils.h"
#include "gtest/gtest.h"

#define private public
#include "ob_log_miner_record_converter.h"
#undef private

namespace oceanbase
{
namespace oblogminer
{

TEST(test_ob_log_miner_record_converter, CsvConverterWriteType)
{
  ObLogMinerRecordCsvConverter converter;
  ObConcurrentFIFOAllocator alloc;
  ObStringBuffer str_buf(&alloc);
  KeyArray key_arr;
  EXPECT_EQ(OB_SUCCESS, alloc.init(1 << 20, 1 << 20, 1 << 13));
  EXPECT_EQ(key_arr.push_back("aaa"), OB_SUCCESS);
  EXPECT_EQ(key_arr.push_back("bbb"), OB_SUCCESS);
  EXPECT_EQ(key_arr.push_back("ccc"), OB_SUCCESS);
  EXPECT_EQ(OB_SUCCESS, converter.write_keys_(key_arr, str_buf));
  EXPECT_STREQ("\"aaa/bbb/ccc\"", str_buf.ptr());
  str_buf.reset();
  EXPECT_EQ(OB_SUCCESS, converter.write_signed_number_(1111, str_buf));
  EXPECT_STREQ("1111", str_buf.ptr());
  str_buf.reset();
  EXPECT_EQ(OB_SUCCESS, converter.write_signed_number_(-12345, str_buf));
  EXPECT_STREQ("-12345", str_buf.ptr());
  str_buf.reset();
  EXPECT_EQ(OB_SUCCESS, converter.write_string_no_escape_("aaaaabbbb'", str_buf));
  EXPECT_STREQ("\"aaaaabbbb'\"", str_buf.ptr());
  str_buf.reset();
  EXPECT_EQ(OB_SUCCESS, converter.write_string_escape_("'aaaa\"\"bbbbb'", str_buf));
  EXPECT_STREQ("\"'aaaa\"\"\"\"bbbbb'\"", str_buf.ptr());
  str_buf.reset();
}

TEST(test_ob_log_miner_record_converter, CsvConverterWriteRecord)
{
  ObLogMinerRecordCsvConverter converter;
  ObConcurrentFIFOAllocator alloc;
  bool is_written = false;
  EXPECT_EQ(OB_SUCCESS, alloc.init(1 << 20, 1 << 20, 1 << 13));
  ObStringBuffer str_buf(&alloc);
  ObLogMinerRecord *rec = nullptr;
  EXPECT_EQ(OB_SUCCESS, converter.set_timezone("+8:00"));
  const char *pkarr1[] = {"aaa", "bbb"};
  const char *ukarr1[] = {"ccc"};
  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "sbtest1", 345, pkarr1, sizeof(pkarr1)/ sizeof(const char*),
        ukarr1, sizeof(ukarr1)/sizeof(const char*), "a/b/c/d/e", EINSERT, 1645539742222222,
        "INSERT INTO \"test\".\"sbtest1\"(\"aaa\",\"bbb\",\"ccc\") VALUES('1','2','3');",
        "DELETE FROM \"test\".\"sbtest1\" WHERE \"aaa\"='1' and \"bbb\"='2' and \"ccc\"='3';");
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(true, is_written);
  EXPECT_STREQ(
    "1002,345,\"aaa/bbb\",\"test_tenant\",\"test\",\"sbtest1\",\"INSERT\",1,1645539742222222000,\"2022-02-22 22:22:22.222222\","
    "\"INSERT INTO \"\"test\"\".\"\"sbtest1\"\"(\"\"aaa\"\",\"\"bbb\"\",\"\"ccc\"\") VALUES('1','2','3');\","
    "\"DELETE FROM \"\"test\"\".\"\"sbtest1\"\" WHERE \"\"aaa\"\"='1' and \"\"bbb\"\"='2' and \"\"ccc\"\"='3';\","
    "1\n", str_buf.ptr());
  str_buf.reset();
  destroy_miner_record(rec);
  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "sbtest1", 345, pkarr1, sizeof(pkarr1)/ sizeof(const char*),
        ukarr1, sizeof(ukarr1)/sizeof(const char*), "a/b/c/d/e", EUPDATE, 0,
        "UPDATE \"test\".\"sbtest1\" SET \"aaa\" = '1', \"bbb\" = '2', \"ccc\" = '3' WHERE "
        "\"aaa\" = '4' AND \"bbb\" = '5' and \"ccc\" = '6' LIMIT 1;",
        "UPDATE \"test\".\"sbtest1\" SET \"aaa\" = '4', \"bbb\" = '5', \"ccc\" = '6' WHERE "
        "\"aaa\" = '1' AND \"bbb\" = '2' and \"ccc\" = '3' LIMIT 1;");
  is_written = false;
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(true, is_written);
  EXPECT_STREQ(
    "1002,345,\"aaa/bbb\",\"test_tenant\",\"test\",\"sbtest1\",\"UPDATE\",2,0,\"1970-01-01 08:00:00.000000\","
    "\"UPDATE \"\"test\"\".\"\"sbtest1\"\" SET \"\"aaa\"\" = '1', \"\"bbb\"\" = '2', \"\"ccc\"\" = '3' WHERE "
    "\"\"aaa\"\" = '4' AND \"\"bbb\"\" = '5' and \"\"ccc\"\" = '6' LIMIT 1;\","
    "\"UPDATE \"\"test\"\".\"\"sbtest1\"\" SET \"\"aaa\"\" = '4', \"\"bbb\"\" = '5', \"\"ccc\"\" = '6' WHERE "
    "\"\"aaa\"\" = '1' AND \"\"bbb\"\" = '2' and \"\"ccc\"\" = '3' LIMIT 1;\","
    "1\n", str_buf.ptr());
  str_buf.reset();
  destroy_miner_record(rec);
  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "", 345, nullptr,0,
        nullptr, 0, nullptr, EDDL, 4611686018427387,
        "CREATE TABLE t1(id INT, name TEXT);",
        nullptr);
  is_written = false;
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(true, is_written);
  EXPECT_STREQ(
    "1002,345,\"\",\"test_tenant\",\"test\",\"\",\"DDL\",4,4611686018427387000,\"2116-02-21 07:53:38.427387\","
    "\"CREATE TABLE t1(id INT, name TEXT);\","
    "\"\","
    "1\n", str_buf.ptr());
  str_buf.reset();
  destroy_miner_record(rec);
  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "sbtest1", 345, pkarr1, sizeof(pkarr1)/ sizeof(const char*),
        ukarr1, sizeof(ukarr1)/sizeof(const char*), "a/b/c/d/e", EDELETE, 0,
        "DELETE FROM \"test\".\"sbtest1\" WHERE \"aaa\"='1' and \"bbb\"='2' and \"ccc\"='3';",
        "INSERT INTO \"test\".\"sbtest1\"(\"aaa\",\"bbb\",\"ccc\") VALUES('1','2','3');"
        );
  is_written = false;
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(true, is_written);
  EXPECT_STREQ(
    "1002,345,\"aaa/bbb\",\"test_tenant\",\"test\",\"sbtest1\",\"DELETE\",3,0,\"1970-01-01 08:00:00.000000\","
    "\"DELETE FROM \"\"test\"\".\"\"sbtest1\"\" WHERE \"\"aaa\"\"='1' and \"\"bbb\"\"='2' and \"\"ccc\"\"='3';\","
    "\"INSERT INTO \"\"test\"\".\"\"sbtest1\"\"(\"\"aaa\"\",\"\"bbb\"\",\"\"ccc\"\") VALUES('1','2','3');\","
    "1\n", str_buf.ptr());
  str_buf.reset();
  destroy_miner_record(rec);
}

TEST(test_ob_log_miner_record_converter, RedoSqlConverterWriteRecord)
{
  ObLogMinerRecordRedoSqlConverter converter;
  ObConcurrentFIFOAllocator alloc;
  bool is_written = false;
  EXPECT_EQ(OB_SUCCESS, alloc.init(1 << 20, 1 << 20, 1 << 13));
  ObStringBuffer str_buf(&alloc);
  ObLogMinerRecord *rec = nullptr;
  const char *pkarr1[] = {"aaa", "bbb"};
  const char *ukarr1[] = {"ccc"};
  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "sbtest1", 345, pkarr1, sizeof(pkarr1)/ sizeof(const char*),
        ukarr1, sizeof(ukarr1)/sizeof(const char*), "a/b/c/d/e", EINSERT, 1645539742222222,
        "INSERT INTO \"test\".\"sbtest1\"(\"aaa\",\"bbb\",\"ccc\") VALUES('1','2','3');",
        "DELETE FROM \"test\".\"sbtest1\" WHERE \"aaa\"='1' and \"bbb\"='2' and \"ccc\"='3';");
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(true, is_written);
  EXPECT_STREQ(
    "INSERT INTO \"test\".\"sbtest1\"(\"aaa\",\"bbb\",\"ccc\") VALUES('1','2','3');\n", str_buf.ptr());
  str_buf.reset();
  destroy_miner_record(rec);

  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "", 345, nullptr,0,
        nullptr, 0, nullptr, EDDL, 4611686018427387,
        "CREATE TABLE t1(id INT, name TEXT);",
        nullptr);
  is_written = false;
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(true, is_written);
  EXPECT_STREQ(
    "CREATE TABLE t1(id INT, name TEXT);\n", str_buf.ptr());
  str_buf.reset();
  destroy_miner_record(rec);

  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "", 345, nullptr,0,
        nullptr, 0, nullptr, EBEGIN, 4611686018427387,
        nullptr,
        nullptr);
  is_written = false;
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(false, is_written);
  destroy_miner_record(rec);
}

TEST(test_ob_log_miner_record_converter, UndoSqlConverterWriteRecord)
{
  ObLogMinerRecordUndoSqlConverter converter;
  ObConcurrentFIFOAllocator alloc;
  bool is_written = false;
  EXPECT_EQ(OB_SUCCESS, alloc.init(1 << 20, 1 << 20, 1 << 13));
  ObStringBuffer str_buf(&alloc);
  ObLogMinerRecord *rec = nullptr;
  const char *pkarr1[] = {"aaa", "bbb"};
  const char *ukarr1[] = {"ccc"};
  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "sbtest1", 345, pkarr1, sizeof(pkarr1)/ sizeof(const char*),
        ukarr1, sizeof(ukarr1)/sizeof(const char*), "a/b/c/d/e", EINSERT, 1645539742222222,
        "INSERT INTO \"test\".\"sbtest1\"(\"aaa\",\"bbb\",\"ccc\") VALUES('1','2','3');",
        "DELETE FROM \"test\".\"sbtest1\" WHERE \"aaa\"='1' and \"bbb\"='2' and \"ccc\"='3';");
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(true, is_written);
  EXPECT_STREQ(
    "DELETE FROM \"test\".\"sbtest1\" WHERE \"aaa\"='1' and \"bbb\"='2' and \"ccc\"='3';\n", str_buf.ptr());
  str_buf.reset();
  destroy_miner_record(rec);

  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "", 345, nullptr, 0,
        nullptr, 0, nullptr, EDDL, 4611686018427387,
        "CREATE TABLE t1(id INT, name TEXT);",
        nullptr);
  is_written = false;
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(false, is_written);
  str_buf.reset();
  destroy_miner_record(rec);

  rec = build_logminer_record(alloc, lib::Worker::CompatMode::MYSQL,
        1002, 1, "test_tenant", "test", "", 345, nullptr,0,
        nullptr, 0, nullptr, EBEGIN, 4611686018427387,
        nullptr,
        nullptr);
  is_written = false;
  EXPECT_EQ(OB_SUCCESS, converter.write_record(*rec, str_buf, is_written));
  EXPECT_EQ(false, is_written);
  destroy_miner_record(rec);
}

}
}

int main(int argc, char **argv)
{
  // testing::FLAGS_gtest_filter = "DO_NOT_RUN";
  system("rm -f test_ob_log_miner_record_converter.log");
  oceanbase::ObLogger &logger = oceanbase::ObLogger::get_logger();
  logger.set_file_name("test_ob_log_miner_record_converter.log", true, false);
  logger.set_log_level("DEBUG");
  logger.set_enable_async_log(false);
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
