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

#define USING_LOG_PREFIX LOGMNR

#include "ob_log_miner.h"
#include "ob_log_miner_args.h"
#include "lib/oblog/ob_log.h"

using namespace oceanbase::oblogminer;
using namespace oceanbase::common;

int main(int argc, char *argv[])
{
  int ret = OB_SUCCESS;
  ObLogMinerArgs args;
  ObLogMiner logminer_instance;

  OB_LOGGER.set_file_name(ObLogMinerArgs::LOGMINER_LOG_FILE, true, false);
  OB_LOGGER.set_log_level("WDIAG");
  OB_LOGGER.set_enable_async_log(false);

  if (OB_FAIL(args.init(argc, argv))) {
    LOG_ERROR("logminer get invalid arguments", K(argc), K(args));
  } else if (args.print_usage_) {
    ObLogMinerCmdArgs::print_usage(argv[0]);
  } else if (OB_FAIL(logminer_instance.init(args))) {
    LOG_ERROR("logminer instance init failed", K(args));
  } else {
    logminer_instance.run();
  }

  return ret;
}