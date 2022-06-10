//
// Created by touwaerio on 2022/6/1.
//

#include <iostream>

#include "log/consoleLog.h"

void vl::core::console_log_writer(const void *ptr, size_t len) {
    std::cout.write(static_cast<const char *>(ptr), len);
}

