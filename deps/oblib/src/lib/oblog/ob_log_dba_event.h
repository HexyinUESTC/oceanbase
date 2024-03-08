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

#ifndef OCEANBASE_LIB_OBLOG_OB_LOG_DBA_EVENT_
#define OCEANBASE_LIB_OBLOG_OB_LOG_DBA_EVENT_

#include "lib/utility/ob_macro_utils.h"

namespace oceanbase
{
namespace common
{
/* Do not use the following macros */
#define DBA_EVENT(event) const char* const event = #event;

#define DBA_EVENTS_1(obj)           DBA_EVENT(obj)
#define DBA_EVENTS_2(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_1(args)
#define DBA_EVENTS_3(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_2(args)
#define DBA_EVENTS_4(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_3(args)
#define DBA_EVENTS_5(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_4(args)
#define DBA_EVENTS_6(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_5(args)
#define DBA_EVENTS_7(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_6(args)
#define DBA_EVENTS_8(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_7(args)
#define DBA_EVENTS_9(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_8(args)
#define DBA_EVENTS_10(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_9(args)
#define DBA_EVENTS_11(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_10(args)
#define DBA_EVENTS_12(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_11(args)
#define DBA_EVENTS_13(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_12(args)
#define DBA_EVENTS_14(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_13(args)
#define DBA_EVENTS_15(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_14(args)
#define DBA_EVENTS_16(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_15(args)
#define DBA_EVENTS_17(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_16(args)
#define DBA_EVENTS_18(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_17(args)
#define DBA_EVENTS_19(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_18(args)
#define DBA_EVENTS_20(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_19(args)
#define DBA_EVENTS_21(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_20(args)
#define DBA_EVENTS_22(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_21(args)
#define DBA_EVENTS_23(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_22(args)
#define DBA_EVENTS_24(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_23(args)
#define DBA_EVENTS_25(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_24(args)
#define DBA_EVENTS_26(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_25(args)
#define DBA_EVENTS_27(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_26(args)
#define DBA_EVENTS_28(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_27(args)
#define DBA_EVENTS_29(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_28(args)
#define DBA_EVENTS_30(obj, args...)  DBA_EVENT(obj); DBA_EVENTS_29(args)

#define DBA_EVENTS_(N, ...) CONCAT(DBA_EVENTS_, N)(__VA_ARGS__)
#define DBA_EVENTS(...) DBA_EVENTS_(ARGS_NUM(__VA_ARGS__), __VA_ARGS__)

#define LIST_EVENT_COUNT(list_name) list_name ##_event_count
#define LIST_CUR_STEP(list_name) list_name ## _cur_step

/* You can define DBA event using the following macros. */
#define DBA_INFO_EVENT(event) DBA_EVENT(event)
#define DBA_WARN_EVENT(event) DBA_EVENT(event)
#define DBA_ERROR_EVENT(event) DBA_EVENT(event)

/* If you need to define a series of steps for a fixed process, you can use the following macro.
 * DEFINE_DBA_EVENT_LIST_H is used in the current file.
 * DEFINE_DBA_EVENT_LIST_CPP is used in the corresponding source code file.
 */
#define DEFINE_DBA_EVENT_LIST_H(list_name, args...) \
  DBA_EVENTS(args); \
  static const int LIST_EVENT_COUNT(list_name) = ARGS_NUM(args);  \
  void list_name##_thread_local_step_reset(); \
  int list_name##_thread_local_step_inc(); \
  int list_name##_thread_local_step_get();

#define DEFINE_DBA_EVENT_LIST_CPP(list_name) \
  static thread_local int LIST_CUR_STEP(list_name); \
  void list_name##_thread_local_step_reset() { LIST_CUR_STEP(list_name) = 0; } \
  int list_name##_thread_local_step_inc()  \
  { \
    LIST_CUR_STEP(list_name) = (LIST_CUR_STEP(list_name) % LIST_EVENT_COUNT(list_name)) + 1;  \
    return LIST_CUR_STEP(list_name);  \
  } \
  int list_name##_thread_local_step_get() { return LIST_CUR_STEP(list_name); }

/* The following macro prints the sequence number of the current step.
 * DBA_STEP_RESET can reset this sequence number, which you can call before the process starts.
 * DBA_STEP_INC_INFO will add one to step, and then print the current step number. (for DBA_INFO, DBA_ERROR)
 * DBA_STEP_INFO just print the current step number. (for DBA_WARN)
 * for example, use DBA_STEP_INC_INFO(init) may print: "[init 2/9] "
 */
#define DBA_STEP_INC_INFO(list_name) "[", #list_name, " ", \
  list_name##_thread_local_step_inc(), "/", \
  LIST_EVENT_COUNT(list_name), "] "
#define DBA_STEP_INFO(list_name) "[", #list_name, " ", \
  list_name##_thread_local_step_get(), "/", \
  LIST_EVENT_COUNT(list_name), "] "
#define DBA_STEP_RESET(list_name) list_name##_thread_local_step_reset();

/* common event (common, lib, share) */
// DBA INFO

// DBA WARN

// DBA ERROR

/* rpc event */

/* system event (server) */

/* sql event */

/* storage event */

/* trans event */

/* rootservice event */
// ERROR
DBA_ERROR_EVENT(OB_ROOTSERVICE_START_FAIL)

/* election event */

/* clog event */
// ERROR
DBA_ERROR_EVENT(OB_CLOG_ALLOCATE_DISK_SPACE_FAIL)
DBA_ERROR_EVENT(OB_CLOG_NEW_DISK_SIZE_NOT_ENOUGH)

/* observer thread start event */
// INFO

DEFINE_DBA_EVENT_LIST_H(server_start,
  OB_SERVER_START_BEGIN,
  OB_SERVER_SYSLOG_SERVICE_INIT_BEGIN,
  OB_SERVER_SYSLOG_SERVICE_INIT_SUCCESS,
  OB_SERVER_INIT_BEGIN,
  OB_SERVER_INIT_SUCCESS,
  OB_SERVER_INSTANCE_START_BEGIN,
  OB_SERVER_INSTANCE_START_SUCCESS,
  OB_SERVER_BLOCK_MANAGER_START_BEGIN,
  OB_SERVER_BLOCK_MANAGER_START_SUCCESS,
  OB_SERVER_WAIT_MULTI_TENANT_SYNCED_BEGIN,
  OB_SERVER_WAIT_MULTI_TENANT_SYNCED_SUCCESS,
  OB_SERVER_WAIT_SCHEMA_READY_BEGIN,
  OB_SERVER_WAIT_SCHEMA_READY_SUCCESS,
  OB_SERVER_CHECK_USER_TENANT_SCHEMA_REFRESHED_BEGIN,
  OB_SERVER_CHECK_USER_TENANT_SCHEMA_REFRESHED_FINISH,
  OB_SERVER_CHECK_LOG_REPLAY_OVER_BEGIN,
  OB_SERVER_CHECK_LOG_REPLAY_OVER_FINISH,
  OB_SERVER_START_SUCCESS
);
DBA_INFO_EVENT(OB_SERVER_WAIT_BEGIN)
DBA_INFO_EVENT(OB_SERVER_WAIT_SUCCESS)
DBA_INFO_EVENT(OB_SERVER_STOP_BEGIN)
DBA_INFO_EVENT(OB_SERVER_STOP_SUCCESS)

// DBA WARN
// DBA ERROR
DBA_ERROR_EVENT(OB_SERVER_SYSLOG_SERVICE_INIT_FAIL)
DBA_ERROR_EVENT(OB_SERVER_INIT_FAIL)
DBA_ERROR_EVENT(OB_SERVER_INSTANCE_START_FAIL)
DBA_ERROR_EVENT(OB_SERVER_BLOCK_MANAGER_START_FAIL)
DBA_ERROR_EVENT(OB_SERVER_WAIT_MULTI_TENANT_SYNCED_FAIL)
DBA_ERROR_EVENT(OB_SERVER_WAIT_SCHEMA_READY_FAIL)
DBA_ERROR_EVENT(OB_SERVER_START_FAIL)
DBA_ERROR_EVENT(OB_SERVER_WAIT_FAIL)
DBA_ERROR_EVENT(OB_SERVER_STOP_FAIL)

/* observer bootstrap event */
// DBA INFO
DEFINE_DBA_EVENT_LIST_H(bootstrap,
  OB_BOOTSTRAP_BEGIN,
  OB_BOOTSTRAP_CREATE_ALL_SCHEMA_BEGIN,
  OB_BOOTSTRAP_CREATE_ALL_SCHEMA_SUCCESS,
  OB_BOOTSTRAP_CREATE_SYS_TENANT_BEGIN,
  OB_BOOTSTRAP_CREATE_SYS_TENANT_SUCCESS,
  OB_BOOTSTRAP_REFRESH_ALL_SCHEMA_BEGIN,
  OB_BOOTSTRAP_REFRESH_ALL_SCHEMA_SUCCESS,
  OB_BOOTSTRAP_WAIT_ALL_ROOTSERVICE_BEGIN,
  OB_BOOTSTRAP_WAIT_ALL_ROOTSERVICE_SUCCESS,
  OB_BOOTSTRAP_SUCCESS
);
DBA_INFO_EVENT(OB_BOOTSTRAP_PREPARE_BEGIN)
DBA_INFO_EVENT(OB_BOOTSTRAP_PREPARE_SUCCESS)

// DBA WARN
// DBA ERROR
DBA_ERROR_EVENT(OB_BOOTSTRAP_PREPARE_FAIL)
DBA_ERROR_EVENT(OB_BOOTSTRAP_CREATE_ALL_SCHEMA_FAIL)
DBA_ERROR_EVENT(OB_BOOTSTRAP_CREATE_SYS_TENANT_FAIL)
DBA_ERROR_EVENT(OB_BOOTSTRAP_REFRESH_ALL_SCHEMA_FAIL)
DBA_ERROR_EVENT(OB_BOOTSTRAP_WAIT_ALL_ROOTSERVICE_FAIL)
DBA_ERROR_EVENT(OB_BOOTSTRAP_FAIL)

} // namespace common
} // namespace oceanbase

#endif  // OCEANBASE_LIB_OBLOG_OB_LOG_DBA_EVENT_
