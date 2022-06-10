//
// Created by touwaerio on 2022/5/29.
//

#include "exception/AllocAddressException.h"


const char *vl::server::AllocAddressException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
    return this->message.c_str();
}

vl::server::AllocAddressException::AllocAddressException(const string &message) : message(message) {}

vl::server::AllocAddressException::AllocAddressException(string &&message) : message(message) {}
