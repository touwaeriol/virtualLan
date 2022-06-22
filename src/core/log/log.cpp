//
// Created by touwaerio on 2022/6/21.
//

#include <log/log.h>


namespace vl::core {

    std::shared_ptr<spdlog::logger> initLog() noexcept {
        return std::make_shared<spdlog::logger>("console");
    }


    std::shared_ptr<spdlog::logger> CONSOLE = initLog();

}