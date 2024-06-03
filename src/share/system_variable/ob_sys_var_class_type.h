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

#ifndef OCEANBASE_SHARE_SYSTEM_VARIABLE_OB_SYS_VAR_CLASS_TYPE_
#define OCEANBASE_SHARE_SYSTEM_VARIABLE_OB_SYS_VAR_CLASS_TYPE_
#include <stdint.h>

namespace oceanbase
{
namespace share
{
enum ObSysVarClassType
{
  SYS_VAR_INVALID = -1,
  SYS_VAR_AUTO_INCREMENT_INCREMENT = 0,
  SYS_VAR_AUTO_INCREMENT_OFFSET = 1,
  SYS_VAR_AUTOCOMMIT = 2,
  SYS_VAR_CHARACTER_SET_CLIENT = 3,
  SYS_VAR_CHARACTER_SET_CONNECTION = 4,
  SYS_VAR_CHARACTER_SET_DATABASE = 5,
  SYS_VAR_CHARACTER_SET_RESULTS = 6,
  SYS_VAR_CHARACTER_SET_SERVER = 7,
  SYS_VAR_CHARACTER_SET_SYSTEM = 8,
  SYS_VAR_COLLATION_CONNECTION = 9,
  SYS_VAR_COLLATION_DATABASE = 10,
  SYS_VAR_COLLATION_SERVER = 11,
  SYS_VAR_INTERACTIVE_TIMEOUT = 12,
  SYS_VAR_LAST_INSERT_ID = 13,
  SYS_VAR_MAX_ALLOWED_PACKET = 14,
  SYS_VAR_SQL_MODE = 15,
  SYS_VAR_TIME_ZONE = 16,
  SYS_VAR_TX_ISOLATION = 17,
  SYS_VAR_VERSION_COMMENT = 18,
  SYS_VAR_WAIT_TIMEOUT = 19,
  SYS_VAR_BINLOG_ROW_IMAGE = 20,
  SYS_VAR_CHARACTER_SET_FILESYSTEM = 21,
  SYS_VAR_CONNECT_TIMEOUT = 22,
  SYS_VAR_DATADIR = 23,
  SYS_VAR_DEBUG_SYNC = 24,
  SYS_VAR_DIV_PRECISION_INCREMENT = 25,
  SYS_VAR_EXPLICIT_DEFAULTS_FOR_TIMESTAMP = 26,
  SYS_VAR_GROUP_CONCAT_MAX_LEN = 27,
  SYS_VAR_IDENTITY = 28,
  SYS_VAR_LOWER_CASE_TABLE_NAMES = 29,
  SYS_VAR_NET_READ_TIMEOUT = 30,
  SYS_VAR_NET_WRITE_TIMEOUT = 31,
  SYS_VAR_READ_ONLY = 32,
  SYS_VAR_SQL_AUTO_IS_NULL = 33,
  SYS_VAR_SQL_SELECT_LIMIT = 34,
  SYS_VAR_TIMESTAMP = 35,
  SYS_VAR_TX_READ_ONLY = 36,
  SYS_VAR_VERSION = 37,
  SYS_VAR_SQL_WARNINGS = 38,
  SYS_VAR_MAX_USER_CONNECTIONS = 39,
  SYS_VAR_INIT_CONNECT = 40,
  SYS_VAR_LICENSE = 41,
  SYS_VAR_NET_BUFFER_LENGTH = 42,
  SYS_VAR_SYSTEM_TIME_ZONE = 43,
  SYS_VAR_QUERY_CACHE_SIZE = 44,
  SYS_VAR_QUERY_CACHE_TYPE = 45,
  SYS_VAR_SQL_QUOTE_SHOW_CREATE = 46,
  SYS_VAR_MAX_SP_RECURSION_DEPTH = 47,
  SYS_VAR_SQL_SAFE_UPDATES = 48,
  SYS_VAR_CONCURRENT_INSERT = 49,
  SYS_VAR_DEFAULT_AUTHENTICATION_PLUGIN = 50,
  SYS_VAR_DISABLED_STORAGE_ENGINES = 51,
  SYS_VAR_ERROR_COUNT = 52,
  SYS_VAR_GENERAL_LOG = 53,
  SYS_VAR_HAVE_OPENSSL = 54,
  SYS_VAR_HAVE_PROFILING = 55,
  SYS_VAR_HAVE_SSL = 56,
  SYS_VAR_HOSTNAME = 57,
  SYS_VAR_LC_MESSAGES = 58,
  SYS_VAR_LOCAL_INFILE = 59,
  SYS_VAR_LOCK_WAIT_TIMEOUT = 60,
  SYS_VAR_LONG_QUERY_TIME = 61,
  SYS_VAR_MAX_CONNECTIONS = 62,
  SYS_VAR_MAX_EXECUTION_TIME = 63,
  SYS_VAR_PROTOCOL_VERSION = 64,
  SYS_VAR_SERVER_ID = 65,
  SYS_VAR_SSL_CA = 66,
  SYS_VAR_SSL_CAPATH = 67,
  SYS_VAR_SSL_CERT = 68,
  SYS_VAR_SSL_CIPHER = 69,
  SYS_VAR_SSL_CRL = 70,
  SYS_VAR_SSL_CRLPATH = 71,
  SYS_VAR_SSL_KEY = 72,
  SYS_VAR_TIME_FORMAT = 73,
  SYS_VAR_TLS_VERSION = 74,
  SYS_VAR_TMP_TABLE_SIZE = 75,
  SYS_VAR_TMPDIR = 76,
  SYS_VAR_UNIQUE_CHECKS = 77,
  SYS_VAR_VERSION_COMPILE_MACHINE = 78,
  SYS_VAR_VERSION_COMPILE_OS = 79,
  SYS_VAR_WARNING_COUNT = 80,
  SYS_VAR_SESSION_TRACK_SCHEMA = 81,
  SYS_VAR_SESSION_TRACK_SYSTEM_VARIABLES = 82,
  SYS_VAR_SESSION_TRACK_STATE_CHANGE = 83,
  SYS_VAR_HAVE_QUERY_CACHE = 84,
  SYS_VAR_QUERY_CACHE_LIMIT = 85,
  SYS_VAR_QUERY_CACHE_MIN_RES_UNIT = 86,
  SYS_VAR_QUERY_CACHE_WLOCK_INVALIDATE = 87,
  SYS_VAR_BINLOG_FORMAT = 88,
  SYS_VAR_BINLOG_CHECKSUM = 89,
  SYS_VAR_BINLOG_ROWS_QUERY_LOG_EVENTS = 90,
  SYS_VAR_LOG_BIN = 91,
  SYS_VAR_SERVER_UUID = 92,
  SYS_VAR_DEFAULT_STORAGE_ENGINE = 93,
  SYS_VAR_CTE_MAX_RECURSION_DEPTH = 94,
  SYS_VAR_REGEXP_STACK_LIMIT = 95,
  SYS_VAR_REGEXP_TIME_LIMIT = 96,
  SYS_VAR_PROFILING = 97,
  SYS_VAR_PROFILING_HISTORY_SIZE = 98,
  SYS_VAR_OB_INTERM_RESULT_MEM_LIMIT = 10001,
  SYS_VAR_OB_PROXY_PARTITION_HIT = 10002,
  SYS_VAR_OB_LOG_LEVEL = 10003,
  SYS_VAR_OB_QUERY_TIMEOUT = 10005,
  SYS_VAR_OB_READ_CONSISTENCY = 10006,
  SYS_VAR_OB_ENABLE_TRANSFORMATION = 10007,
  SYS_VAR_OB_TRX_TIMEOUT = 10008,
  SYS_VAR_OB_ENABLE_PLAN_CACHE = 10009,
  SYS_VAR_OB_ENABLE_INDEX_DIRECT_SELECT = 10010,
  SYS_VAR_OB_PROXY_SET_TRX_EXECUTED = 10011,
  SYS_VAR_OB_ENABLE_AGGREGATION_PUSHDOWN = 10012,
  SYS_VAR_OB_LAST_SCHEMA_VERSION = 10013,
  SYS_VAR_OB_GLOBAL_DEBUG_SYNC = 10014,
  SYS_VAR_OB_PROXY_GLOBAL_VARIABLES_VERSION = 10015,
  SYS_VAR_OB_ENABLE_SHOW_TRACE = 10016,
  SYS_VAR_OB_BNL_JOIN_CACHE_SIZE = 10019,
  SYS_VAR_OB_PROXY_USER_PRIVILEGE = 10020,
  SYS_VAR_OB_ORG_CLUSTER_ID = 10021,
  SYS_VAR_OB_PLAN_CACHE_PERCENTAGE = 10022,
  SYS_VAR_OB_PLAN_CACHE_EVICT_HIGH_PERCENTAGE = 10023,
  SYS_VAR_OB_PLAN_CACHE_EVICT_LOW_PERCENTAGE = 10024,
  SYS_VAR_RECYCLEBIN = 10025,
  SYS_VAR_OB_CAPABILITY_FLAG = 10026,
  SYS_VAR_IS_RESULT_ACCURATE = 10028,
  SYS_VAR_ERROR_ON_OVERLAP_TIME = 10029,
  SYS_VAR_OB_COMPATIBILITY_MODE = 10030,
  SYS_VAR_OB_SQL_WORK_AREA_PERCENTAGE = 10032,
  SYS_VAR_OB_SAFE_WEAK_READ_SNAPSHOT = 10033,
  SYS_VAR_OB_ROUTE_POLICY = 10034,
  SYS_VAR_OB_ENABLE_TRANSMISSION_CHECKSUM = 10035,
  SYS_VAR_FOREIGN_KEY_CHECKS = 10036,
  SYS_VAR_OB_STATEMENT_TRACE_ID = 10037,
  SYS_VAR_OB_ENABLE_TRUNCATE_FLASHBACK = 10038,
  SYS_VAR_OB_TCP_INVITED_NODES = 10039,
  SYS_VAR_SQL_THROTTLE_CURRENT_PRIORITY = 10040,
  SYS_VAR_SQL_THROTTLE_PRIORITY = 10041,
  SYS_VAR_SQL_THROTTLE_RT = 10042,
  SYS_VAR_SQL_THROTTLE_CPU = 10043,
  SYS_VAR_SQL_THROTTLE_IO = 10044,
  SYS_VAR_SQL_THROTTLE_NETWORK = 10045,
  SYS_VAR_SQL_THROTTLE_LOGICAL_READS = 10046,
  SYS_VAR_AUTO_INCREMENT_CACHE_SIZE = 10047,
  SYS_VAR_OB_ENABLE_JIT = 10048,
  SYS_VAR_OB_TEMP_TABLESPACE_SIZE_PERCENTAGE = 10049,
  SYS_VAR_PLUGIN_DIR = 10052,
  SYS_VAR_OB_SQL_AUDIT_PERCENTAGE = 10055,
  SYS_VAR_OB_ENABLE_SQL_AUDIT = 10056,
  SYS_VAR_OPTIMIZER_USE_SQL_PLAN_BASELINES = 10057,
  SYS_VAR_OPTIMIZER_CAPTURE_SQL_PLAN_BASELINES = 10058,
  SYS_VAR_PARALLEL_SERVERS_TARGET = 10060,
  SYS_VAR_OB_EARLY_LOCK_RELEASE = 10061,
  SYS_VAR_OB_TRX_IDLE_TIMEOUT = 10062,
  SYS_VAR_BLOCK_ENCRYPTION_MODE = 10063,
  SYS_VAR_NLS_DATE_FORMAT = 10064,
  SYS_VAR_NLS_TIMESTAMP_FORMAT = 10065,
  SYS_VAR_NLS_TIMESTAMP_TZ_FORMAT = 10066,
  SYS_VAR_OB_RESERVED_META_MEMORY_PERCENTAGE = 10067,
  SYS_VAR_OB_CHECK_SYS_VARIABLE = 10068,
  SYS_VAR_NLS_LANGUAGE = 10069,
  SYS_VAR_NLS_TERRITORY = 10070,
  SYS_VAR_NLS_SORT = 10071,
  SYS_VAR_NLS_COMP = 10072,
  SYS_VAR_NLS_CHARACTERSET = 10073,
  SYS_VAR_NLS_NCHAR_CHARACTERSET = 10074,
  SYS_VAR_NLS_DATE_LANGUAGE = 10075,
  SYS_VAR_NLS_LENGTH_SEMANTICS = 10076,
  SYS_VAR_NLS_NCHAR_CONV_EXCP = 10077,
  SYS_VAR_NLS_CALENDAR = 10078,
  SYS_VAR_NLS_NUMERIC_CHARACTERS = 10079,
  SYS_VAR__NLJ_BATCHING_ENABLED = 10080,
  SYS_VAR_TRACEFILE_IDENTIFIER = 10081,
  SYS_VAR__GROUPBY_NOPUSHDOWN_CUT_RATIO = 10082,
  SYS_VAR__PX_BROADCAST_FUDGE_FACTOR = 10083,
  SYS_VAR_TRANSACTION_ISOLATION = 10085,
  SYS_VAR_OB_TRX_LOCK_TIMEOUT = 10086,
  SYS_VAR_VALIDATE_PASSWORD_CHECK_USER_NAME = 10087,
  SYS_VAR_VALIDATE_PASSWORD_LENGTH = 10088,
  SYS_VAR_VALIDATE_PASSWORD_MIXED_CASE_COUNT = 10089,
  SYS_VAR_VALIDATE_PASSWORD_NUMBER_COUNT = 10090,
  SYS_VAR_VALIDATE_PASSWORD_POLICY = 10091,
  SYS_VAR_VALIDATE_PASSWORD_SPECIAL_CHAR_COUNT = 10092,
  SYS_VAR_DEFAULT_PASSWORD_LIFETIME = 10093,
  SYS_VAR__OB_OLS_POLICY_SESSION_LABELS = 10094,
  SYS_VAR_OB_TRACE_INFO = 10095,
  SYS_VAR__PX_PARTITION_SCAN_THRESHOLD = 10097,
  SYS_VAR__OB_PX_BCAST_OPTIMIZATION = 10098,
  SYS_VAR__OB_PX_SLAVE_MAPPING_THRESHOLD = 10099,
  SYS_VAR__ENABLE_PARALLEL_DML = 10100,
  SYS_VAR__PX_MIN_GRANULES_PER_SLAVE = 10101,
  SYS_VAR_SECURE_FILE_PRIV = 10102,
  SYS_VAR_PLSQL_WARNINGS = 10103,
  SYS_VAR__ENABLE_PARALLEL_QUERY = 10104,
  SYS_VAR__FORCE_PARALLEL_QUERY_DOP = 10105,
  SYS_VAR__FORCE_PARALLEL_DML_DOP = 10106,
  SYS_VAR_OB_PL_BLOCK_TIMEOUT = 10107,
  SYS_VAR_TRANSACTION_READ_ONLY = 10108,
  SYS_VAR_RESOURCE_MANAGER_PLAN = 10109,
  SYS_VAR_PERFORMANCE_SCHEMA = 10110,
  SYS_VAR_NLS_CURRENCY = 10111,
  SYS_VAR_NLS_ISO_CURRENCY = 10112,
  SYS_VAR_NLS_DUAL_CURRENCY = 10113,
  SYS_VAR_PLSQL_CCFLAGS = 10115,
  SYS_VAR__OB_PROXY_SESSION_TEMPORARY_TABLE_USED = 10116,
  SYS_VAR__ENABLE_PARALLEL_DDL = 10117,
  SYS_VAR__FORCE_PARALLEL_DDL_DOP = 10118,
  SYS_VAR_CURSOR_SHARING = 10119,
  SYS_VAR__OPTIMIZER_NULL_AWARE_ANTIJOIN = 10120,
  SYS_VAR__PX_PARTIAL_ROLLUP_PUSHDOWN = 10121,
  SYS_VAR__PX_DIST_AGG_PARTIAL_ROLLUP_PUSHDOWN = 10122,
  SYS_VAR__CREATE_AUDIT_PURGE_JOB = 10123,
  SYS_VAR__DROP_AUDIT_PURGE_JOB = 10124,
  SYS_VAR__SET_PURGE_JOB_INTERVAL = 10125,
  SYS_VAR__SET_PURGE_JOB_STATUS = 10126,
  SYS_VAR__SET_LAST_ARCHIVE_TIMESTAMP = 10127,
  SYS_VAR__CLEAR_LAST_ARCHIVE_TIMESTAMP = 10128,
  SYS_VAR__AGGREGATION_OPTIMIZATION_SETTINGS = 10129,
  SYS_VAR__PX_SHARED_HASH_JOIN = 10130,
  SYS_VAR_SQL_NOTES = 10131,
  SYS_VAR_INNODB_STRICT_MODE = 10132,
  SYS_VAR__WINDOWFUNC_OPTIMIZATION_SETTINGS = 10133,
  SYS_VAR_OB_ENABLE_RICH_ERROR_MSG = 10134,
  SYS_VAR_LOG_ROW_VALUE_OPTIONS = 10136,
  SYS_VAR_OB_MAX_READ_STALE_TIME = 10137,
  SYS_VAR__OPTIMIZER_GATHER_STATS_ON_LOAD = 10138,
  SYS_VAR__SET_REVERSE_DBLINK_INFOS = 10139,
  SYS_VAR__FORCE_ORDER_PRESERVE_SET = 10140,
  SYS_VAR__SHOW_DDL_IN_COMPAT_MODE = 10141,
  SYS_VAR_PARALLEL_DEGREE_POLICY = 10142,
  SYS_VAR_PARALLEL_DEGREE_LIMIT = 10143,
  SYS_VAR_PARALLEL_MIN_SCAN_TIME_THRESHOLD = 10144,
  SYS_VAR_OPTIMIZER_DYNAMIC_SAMPLING = 10145,
  SYS_VAR_RUNTIME_FILTER_TYPE = 10146,
  SYS_VAR_RUNTIME_FILTER_WAIT_TIME_MS = 10147,
  SYS_VAR_RUNTIME_FILTER_MAX_IN_NUM = 10148,
  SYS_VAR_RUNTIME_BLOOM_FILTER_MAX_SIZE = 10149,
  SYS_VAR_OPTIMIZER_FEATURES_ENABLE = 10150,
  SYS_VAR__OB_PROXY_WEAKREAD_FEEDBACK = 10151,
  SYS_VAR_NCHARACTER_SET_CONNECTION = 10152,
  SYS_VAR_AUTOMATIC_SP_PRIVILEGES = 10153,
  SYS_VAR_PRIVILEGE_FEATURES_ENABLE = 10154,
  SYS_VAR__PRIV_CONTROL = 10155,
  SYS_VAR__ENABLE_MYSQL_PL_PRIV_CHECK = 10156,
  SYS_VAR_OB_ENABLE_PL_CACHE = 10157,
  SYS_VAR_OB_DEFAULT_LOB_INROW_THRESHOLD = 10158,
  SYS_VAR__ENABLE_STORAGE_CARDINALITY_ESTIMATION = 10159,
  SYS_VAR_LC_TIME_NAMES = 10160,
  SYS_VAR_ACTIVATE_ALL_ROLES_ON_LOGIN = 10161,
  SYS_VAR_INNODB_STATS_PERSISTENT = 10163,
  SYS_VAR_DEBUG = 10164,
  SYS_VAR_INNODB_CHANGE_BUFFERING_DEBUG = 10165,
  SYS_VAR_INNODB_COMPRESS_DEBUG = 10166,
  SYS_VAR_INNODB_DISABLE_RESIZE_BUFFER_POOL_DEBUG = 10167,
  SYS_VAR_INNODB_FIL_MAKE_PAGE_DIRTY_DEBUG = 10168,
  SYS_VAR_INNODB_LIMIT_OPTIMISTIC_INSERT_DEBUG = 10169,
  SYS_VAR_INNODB_MERGE_THRESHOLD_SET_ALL_DEBUG = 10170,
  SYS_VAR_INNODB_SAVED_PAGE_NUMBER_DEBUG = 10171,
  SYS_VAR_INNODB_TRX_PURGE_VIEW_UPDATE_ONLY_DEBUG = 10172,
  SYS_VAR_INNODB_TRX_RSEG_N_SLOTS_DEBUG = 10173,
  SYS_VAR_STORED_PROGRAM_CACHE = 10174,
  SYS_VAR_OB_COMPATIBILITY_CONTROL = 10175,
  SYS_VAR_OB_COMPATIBILITY_VERSION = 10176,
  SYS_VAR_OB_SECURITY_VERSION = 10177,
  SYS_VAR_CARDINALITY_ESTIMATION_MODEL = 10178,
  SYS_VAR_FLUSH = 10181,
  SYS_VAR_FLUSH_TIME = 10182,
  SYS_VAR_INNODB_ADAPTIVE_FLUSHING = 10183,
  SYS_VAR_INNODB_ADAPTIVE_FLUSHING_LWM = 10184,
  SYS_VAR_INNODB_ADAPTIVE_HASH_INDEX = 10185,
  SYS_VAR_INNODB_ADAPTIVE_HASH_INDEX_PARTS = 10186,
  SYS_VAR_INNODB_ADAPTIVE_MAX_SLEEP_DELAY = 10187,
  SYS_VAR_INNODB_AUTOEXTEND_INCREMENT = 10188,
  SYS_VAR_INNODB_BACKGROUND_DROP_LIST_EMPTY = 10189,
  SYS_VAR_INNODB_BUFFER_POOL_DUMP_AT_SHUTDOWN = 10190,
  SYS_VAR_INNODB_BUFFER_POOL_DUMP_NOW = 10191,
  SYS_VAR_INNODB_BUFFER_POOL_DUMP_PCT = 10192,
  SYS_VAR_INNODB_BUFFER_POOL_FILENAME = 10193,
  SYS_VAR_INNODB_BUFFER_POOL_LOAD_ABORT = 10194,
  SYS_VAR_INNODB_BUFFER_POOL_LOAD_NOW = 10195,
  SYS_VAR_INNODB_BUFFER_POOL_SIZE = 10196,
  SYS_VAR_INNODB_CHANGE_BUFFER_MAX_SIZE = 10197,
  SYS_VAR_INNODB_CHANGE_BUFFERING = 10198,
  SYS_VAR_INNODB_CHECKSUM_ALGORITHM = 10199,
  SYS_VAR_INNODB_CMP_PER_INDEX_ENABLED = 10200,
  SYS_VAR_INNODB_COMMIT_CONCURRENCY = 10201,
  SYS_VAR_INNODB_COMPRESSION_FAILURE_THRESHOLD_PCT = 10202,
  SYS_VAR_INNODB_COMPRESSION_LEVEL = 10203,
  SYS_VAR_INNODB_COMPRESSION_PAD_PCT_MAX = 10204,
  SYS_VAR_INNODB_CONCURRENCY_TICKETS = 10205,
  SYS_VAR_INNODB_DEFAULT_ROW_FORMAT = 10206,
  SYS_VAR_INNODB_DISABLE_SORT_FILE_CACHE = 10207,
  SYS_VAR_INNODB_FILE_FORMAT = 10208,
  SYS_VAR_INNODB_FILE_FORMAT_MAX = 10209,
  SYS_VAR_INNODB_FILE_PER_TABLE = 10210,
  SYS_VAR_INNODB_FILL_FACTOR = 10211,
  SYS_VAR_INNODB_FLUSH_NEIGHBORS = 10212,
  SYS_VAR_INNODB_FLUSH_SYNC = 10213,
  SYS_VAR_INNODB_FLUSHING_AVG_LOOPS = 10214,
  SYS_VAR_INNODB_LRU_SCAN_DEPTH = 10215,
  SYS_VAR_INNODB_MAX_DIRTY_PAGES_PCT = 10216,
  SYS_VAR_INNODB_MAX_DIRTY_PAGES_PCT_LWM = 10217,
  SYS_VAR_INNODB_MAX_PURGE_LAG = 10218,
  SYS_VAR_INNODB_MAX_PURGE_LAG_DELAY = 10219,
  SYS_VAR_HAVE_SYMLINK = 10220,
  SYS_VAR_IGNORE_BUILTIN_INNODB = 10221,
  SYS_VAR_INNODB_BUFFER_POOL_CHUNK_SIZE = 10222,
  SYS_VAR_INNODB_BUFFER_POOL_INSTANCES = 10223,
  SYS_VAR_INNODB_BUFFER_POOL_LOAD_AT_STARTUP = 10224,
  SYS_VAR_INNODB_CHECKSUMS = 10225,
  SYS_VAR_INNODB_DOUBLEWRITE = 10226,
  SYS_VAR_INNODB_FILE_FORMAT_CHECK = 10227,
  SYS_VAR_INNODB_FLUSH_METHOD = 10228,
  SYS_VAR_INNODB_FORCE_LOAD_CORRUPTED = 10229,
  SYS_VAR_INNODB_PAGE_SIZE = 10230,
  SYS_VAR_INNODB_VERSION = 10231,
  SYS_VAR_MYISAM_MMAP_SIZE = 10232,
  SYS_VAR_TABLE_OPEN_CACHE_INSTANCES = 10233,
  SYS_VAR_GTID_EXECUTED = 10234,
  SYS_VAR_GTID_OWNED = 10235,
  SYS_VAR_INNODB_ROLLBACK_ON_TIMEOUT = 10236,
  SYS_VAR_COMPLETION_TYPE = 10237,
  SYS_VAR_ENFORCE_GTID_CONSISTENCY = 10238,
  SYS_VAR_GTID_EXECUTED_COMPRESSION_PERIOD = 10239,
  SYS_VAR_GTID_MODE = 10240,
  SYS_VAR_GTID_NEXT = 10241,
  SYS_VAR_GTID_PURGED = 10242,
  SYS_VAR_INNODB_API_BK_COMMIT_INTERVAL = 10243,
  SYS_VAR_INNODB_API_TRX_LEVEL = 10244,
  SYS_VAR_INNODB_SUPPORT_XA = 10245,
  SYS_VAR_SESSION_TRACK_GTIDS = 10246,
  SYS_VAR_SESSION_TRACK_TRANSACTION_INFO = 10247,
  SYS_VAR_TRANSACTION_ALLOC_BLOCK_SIZE = 10248,
  SYS_VAR_TRANSACTION_ALLOW_BATCHING = 10249,
  SYS_VAR_TRANSACTION_PREALLOC_SIZE = 10250,
  SYS_VAR_TRANSACTION_WRITE_SET_EXTRACTION = 10251,
  SYS_VAR_INFORMATION_SCHEMA_STATS_EXPIRY = 10252,
  SYS_VAR__ORACLE_SQL_SELECT_LIMIT = 10253,
  SYS_VAR_GROUP_REPLICATION_ALLOW_LOCAL_DISJOINT_GTIDS_JOIN = 10254,
  SYS_VAR_GROUP_REPLICATION_ALLOW_LOCAL_LOWER_VERSION_JOIN = 10255,
  SYS_VAR_GROUP_REPLICATION_AUTO_INCREMENT_INCREMENT = 10256,
  SYS_VAR_GROUP_REPLICATION_BOOTSTRAP_GROUP = 10257,
  SYS_VAR_GROUP_REPLICATION_COMPONENTS_STOP_TIMEOUT = 10258,
  SYS_VAR_GROUP_REPLICATION_COMPRESSION_THRESHOLD = 10259,
  SYS_VAR_GROUP_REPLICATION_ENFORCE_UPDATE_EVERYWHERE_CHECKS = 10260,
  SYS_VAR_GROUP_REPLICATION_EXIT_STATE_ACTION = 10261,
  SYS_VAR_GROUP_REPLICATION_FLOW_CONTROL_APPLIER_THRESHOLD = 10262,
  SYS_VAR_GROUP_REPLICATION_FLOW_CONTROL_CERTIFIER_THRESHOLD = 10263,
  SYS_VAR_GROUP_REPLICATION_FLOW_CONTROL_MODE = 10264,
  SYS_VAR_GROUP_REPLICATION_FORCE_MEMBERS = 10265,
  SYS_VAR_GROUP_REPLICATION_GROUP_NAME = 10266,
  SYS_VAR_GROUP_REPLICATION_GTID_ASSIGNMENT_BLOCK_SIZE = 10267,
  SYS_VAR_GROUP_REPLICATION_IP_WHITELIST = 10268,
  SYS_VAR_GROUP_REPLICATION_LOCAL_ADDRESS = 10269,
  SYS_VAR_GROUP_REPLICATION_MEMBER_WEIGHT = 10270,
  SYS_VAR_GROUP_REPLICATION_POLL_SPIN_LOOPS = 10271,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_COMPLETE_AT = 10272,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_RECONNECT_INTERVAL = 10273,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_RETRY_COUNT = 10274,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_SSL_CA = 10275,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_SSL_CAPATH = 10276,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_SSL_CERT = 10277,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_SSL_CIPHER = 10278,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_SSL_CRL = 10279,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_SSL_CRLPATH = 10280,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_SSL_KEY = 10281,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_SSL_VERIFY_SERVER_CERT = 10282,
  SYS_VAR_GROUP_REPLICATION_RECOVERY_USE_SSL = 10283,
  SYS_VAR_GROUP_REPLICATION_SINGLE_PRIMARY_MODE = 10284,
  SYS_VAR_GROUP_REPLICATION_SSL_MODE = 10285,
  SYS_VAR_GROUP_REPLICATION_START_ON_BOOT = 10286,
  SYS_VAR_GROUP_REPLICATION_TRANSACTION_SIZE_LIMIT = 10287,
  SYS_VAR_GROUP_REPLICATION_UNREACHABLE_MAJORITY_TIMEOUT = 10288,
  SYS_VAR_INNODB_REPLICATION_DELAY = 10289,
  SYS_VAR_MASTER_INFO_REPOSITORY = 10290,
  SYS_VAR_MASTER_VERIFY_CHECKSUM = 10291,
  SYS_VAR_PSEUDO_SLAVE_MODE = 10292,
  SYS_VAR_PSEUDO_THREAD_ID = 10293,
  SYS_VAR_RBR_EXEC_MODE = 10294,
  SYS_VAR_REPLICATION_OPTIMIZE_FOR_STATIC_PLUGIN_CONFIG = 10295,
  SYS_VAR_REPLICATION_SENDER_OBSERVE_COMMIT_ONLY = 10296,
  SYS_VAR_RPL_SEMI_SYNC_MASTER_ENABLED = 10297,
  SYS_VAR_RPL_SEMI_SYNC_MASTER_TIMEOUT = 10298,
  SYS_VAR_RPL_SEMI_SYNC_MASTER_TRACE_LEVEL = 10299,
  SYS_VAR_RPL_SEMI_SYNC_MASTER_WAIT_FOR_SLAVE_COUNT = 10300,
  SYS_VAR_RPL_SEMI_SYNC_MASTER_WAIT_NO_SLAVE = 10301,
  SYS_VAR_RPL_SEMI_SYNC_MASTER_WAIT_POINT = 10302,
  SYS_VAR_RPL_SEMI_SYNC_SLAVE_ENABLED = 10303,
  SYS_VAR_RPL_SEMI_SYNC_SLAVE_TRACE_LEVEL = 10304,
  SYS_VAR_RPL_STOP_SLAVE_TIMEOUT = 10305,
  SYS_VAR_SLAVE_ALLOW_BATCHING = 10306,
  SYS_VAR_SLAVE_CHECKPOINT_GROUP = 10307,
  SYS_VAR_SLAVE_CHECKPOINT_PERIOD = 10308,
  SYS_VAR_SLAVE_COMPRESSED_PROTOCOL = 10309,
  SYS_VAR_SLAVE_EXEC_MODE = 10310,
  SYS_VAR_SLAVE_MAX_ALLOWED_PACKET = 10311,
  SYS_VAR_SLAVE_NET_TIMEOUT = 10312,
  SYS_VAR_SLAVE_PARALLEL_TYPE = 10313,
  SYS_VAR_SLAVE_PARALLEL_WORKERS = 10314,
  SYS_VAR_SLAVE_PENDING_JOBS_SIZE_MAX = 10315,
  SYS_VAR_SLAVE_PRESERVE_COMMIT_ORDER = 10316,
  SYS_VAR_SLAVE_SQL_VERIFY_CHECKSUM = 10317,
  SYS_VAR_SLAVE_TRANSACTION_RETRIES = 10318,
  SYS_VAR_SQL_SLAVE_SKIP_COUNTER = 10319,
  SYS_VAR_INNODB_FORCE_RECOVERY = 10320,
  SYS_VAR_SKIP_SLAVE_START = 10321,
  SYS_VAR_SLAVE_LOAD_TMPDIR = 10322,
  SYS_VAR_SLAVE_SKIP_ERRORS = 10323,
  SYS_VAR_DEFAULT_COLLATION_FOR_UTF8MB4 = 10325,
  SYS_VAR__ENABLE_OLD_CHARSET_AGGREGATION = 10326,
  SYS_VAR_ENABLE_SQL_PLAN_MONITOR = 10327,
  SYS_VAR_INSERT_ID = 10328,
  SYS_VAR_JOIN_BUFFER_SIZE = 10329,
  SYS_VAR_MAX_JOIN_SIZE = 10330,
  SYS_VAR_MAX_LENGTH_FOR_SORT_DATA = 10331,
  SYS_VAR_MAX_PREPARED_STMT_COUNT = 10332,
  SYS_VAR_MAX_SORT_LENGTH = 10333,
  SYS_VAR_MIN_EXAMINED_ROW_LIMIT = 10334,
  SYS_VAR_MULTI_RANGE_COUNT = 10335,
  SYS_VAR_MYSQLX_CONNECT_TIMEOUT = 10336,
  SYS_VAR_MYSQLX_IDLE_WORKER_THREAD_TIMEOUT = 10337,
  SYS_VAR_MYSQLX_MAX_ALLOWED_PACKET = 10338,
  SYS_VAR_MYSQLX_MAX_CONNECTIONS = 10339,
  SYS_VAR_MYSQLX_MIN_WORKER_THREADS = 10340,
  SYS_VAR_PERFORMANCE_SCHEMA_SHOW_PROCESSLIST = 10341,
  SYS_VAR_QUERY_ALLOC_BLOCK_SIZE = 10342,
  SYS_VAR_QUERY_PREALLOC_SIZE = 10343,
  SYS_VAR_SLOW_QUERY_LOG = 10344,
  SYS_VAR_SLOW_QUERY_LOG_FILE = 10345,
  SYS_VAR_SORT_BUFFER_SIZE = 10346,
  SYS_VAR_SQL_BUFFER_RESULT = 10347,
  SYS_VAR_BINLOG_CACHE_SIZE = 10348,
  SYS_VAR_BINLOG_DIRECT_NON_TRANSACTIONAL_UPDATES = 10349,
  SYS_VAR_BINLOG_ERROR_ACTION = 10350,
  SYS_VAR_BINLOG_GROUP_COMMIT_SYNC_DELAY = 10351,
  SYS_VAR_BINLOG_GROUP_COMMIT_SYNC_NO_DELAY_COUNT = 10352,
  SYS_VAR_BINLOG_MAX_FLUSH_QUEUE_TIME = 10353,
  SYS_VAR_BINLOG_ORDER_COMMITS = 10354,
  SYS_VAR_BINLOG_STMT_CACHE_SIZE = 10355,
  SYS_VAR_BINLOG_TRANSACTION_DEPENDENCY_HISTORY_SIZE = 10356,
  SYS_VAR_BINLOG_TRANSACTION_DEPENDENCY_TRACKING = 10357,
  SYS_VAR_EXPIRE_LOGS_DAYS = 10358,
  SYS_VAR_INNODB_FLUSH_LOG_AT_TIMEOUT = 10359,
  SYS_VAR_INNODB_FLUSH_LOG_AT_TRX_COMMIT = 10360,
  SYS_VAR_INNODB_LOG_CHECKPOINT_NOW = 10361,
  SYS_VAR_INNODB_LOG_CHECKSUMS = 10362,
  SYS_VAR_INNODB_LOG_COMPRESSED_PAGES = 10363,
  SYS_VAR_INNODB_LOG_WRITE_AHEAD_SIZE = 10364,
  SYS_VAR_INNODB_MAX_UNDO_LOG_SIZE = 10365,
  SYS_VAR_INNODB_ONLINE_ALTER_LOG_MAX_SIZE = 10366,
  SYS_VAR_INNODB_UNDO_LOG_TRUNCATE = 10367,
  SYS_VAR_INNODB_UNDO_LOGS = 10368,
  SYS_VAR_LOG_BIN_TRUST_FUNCTION_CREATORS = 10369,
  SYS_VAR_LOG_BIN_USE_V1_ROW_EVENTS = 10370,
  SYS_VAR_LOG_BUILTIN_AS_IDENTIFIED_BY_PASSWORD = 10371,
  SYS_VAR_MAX_BINLOG_CACHE_SIZE = 10372,
  SYS_VAR_MAX_BINLOG_SIZE = 10373,
  SYS_VAR_MAX_BINLOG_STMT_CACHE_SIZE = 10374,
  SYS_VAR_MAX_RELAY_LOG_SIZE = 10375,
  SYS_VAR_RELAY_LOG_INFO_REPOSITORY = 10376,
  SYS_VAR_RELAY_LOG_PURGE = 10377,
  SYS_VAR_SYNC_BINLOG = 10378,
  SYS_VAR_SYNC_RELAY_LOG = 10379,
  SYS_VAR_SYNC_RELAY_LOG_INFO = 10380,
  SYS_VAR_INNODB_DEADLOCK_DETECT = 10381,
  SYS_VAR_INNODB_LOCK_WAIT_TIMEOUT = 10382,
  SYS_VAR_INNODB_PRINT_ALL_DEADLOCKS = 10383,
  SYS_VAR_INNODB_TABLE_LOCKS = 10384,
  SYS_VAR_MAX_WRITE_LOCK_COUNT = 10385,
  SYS_VAR_INNODB_READ_ONLY = 10387,
  SYS_VAR_INNODB_API_DISABLE_ROWLOCK = 10388,
  SYS_VAR_INNODB_AUTOINC_LOCK_MODE = 10389,
  SYS_VAR_SKIP_EXTERNAL_LOCKING = 10390,
  SYS_VAR_SUPER_READ_ONLY = 10391,
  SYS_VAR_LOW_PRIORITY_UPDATES = 10394,
  SYS_VAR_MAX_ERROR_COUNT = 10395,
  SYS_VAR_MAX_INSERT_DELAYED_THREADS = 10396,
};

}
}
#endif //OCEANBASE_SHARE_SYSTEM_VARIABLE_OB_SYS_VAR_CLASS_TYPE_