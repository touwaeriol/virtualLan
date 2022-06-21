//
// Created by touwaerio on 2022/6/21.
//

#ifndef VIRTUALLAN_LOG_H
#define VIRTUALLAN_LOG_H

#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace vl::core{

   void initLog();

   extern const spdlog::logger console;


}

#endif //VIRTUALLAN_LOG_H
