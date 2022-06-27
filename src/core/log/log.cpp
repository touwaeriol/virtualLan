//
// Created by touwaerio on 2022/6/21.
//

#include <log/log.h>


namespace vl::core {

    void initLog() noexcept {
        spdlog::set_level(spdlog::level::debug);
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [%t] %g:%# %!(): %v");
        spdlog::enable_backtrace(32);
    }


}