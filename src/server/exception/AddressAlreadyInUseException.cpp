//
// Created by touwaerio on 2022/5/29.
//

#include "exception/AddressAlreadyInUseException.h"


vl::server::AddressAlreadyInUseException::AddressAlreadyInUseException(const string &message) : AllocAddressException(
        message) {}

vl::server::AddressAlreadyInUseException::AddressAlreadyInUseException(string &&message) : AllocAddressException(
        message) {}


const char *vl::server::AddressAlreadyInUseException::what() const noexcept {
    return AllocAddressException::what();
}

