//
// Created by touwaerio on 2022/6/21.
//

#ifndef VIRTUALLAN_LOG_H
#define VIRTUALLAN_LOG_H

#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


#define TLOG(msg) spdlog::trace(msg);

#define DLOG(msg) spdlog::debug(msg);

#define ILOG(msg) spdlog::info(msg);

#define WLOG(msg) spdlog::warn(msg);

#define ELOG(msg) spdlog::error(msg);

#define CLOG(msg) spdlog::critical(msg);


namespace vl::core {

    std::shared_ptr<spdlog::logger> initLog() noexcept;

    extern std::shared_ptr<spdlog::logger> CONSOLE;


}

#endif //VIRTUALLAN_LOG_H
