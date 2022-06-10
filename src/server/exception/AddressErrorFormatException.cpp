//
// Created by touwaerio on 2022/5/29.
//

#include "exception/AddressErrorFormatException.h"

vl::server::AddressErrorFormatException::AddressErrorFormatException(const string &message) : AllocAddressException(
        message) {}

vl::server::AddressErrorFormatException::AddressErrorFormatException(string &&message) : AllocAddressException(
        message) {}

const char *vl::server::AddressErrorFormatException::what() const noexcept {
    return AllocAddressException::what();
}


