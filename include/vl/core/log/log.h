//
// Created by touwaerio on 2022/6/21.
//

#ifndef VIRTUALLAN_LOG_H
#define VIRTUALLAN_LOG_H

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#define TLOG(msg) SPDLOG_TRACE(msg);
#define DLOG(msg) SPDLOG_DEBUG(msg);
#define ILOG(msg) SPDLOG_INFO(msg);
#define WLOG(msg) SPDLOG_WARN(msg);
#define ELOG(msg) SPDLOG_ERROR(msg);
#define CLOG(msg) SPDLOG_CRITICAL(msg);


#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>





namespace vl::core {

    void initLog() noexcept;


}

#endif //VIRTUALLAN_LOG_H
