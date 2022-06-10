//
// Created by touwaerio on 2022/5/29.
//

#include "exception/AddressPoolFullException.h"

vl::server::AddressPoolFullException::AddressPoolFullException(const string &message) : AllocAddressException(
        message) {}

vl::server::AddressPoolFullException::AddressPoolFullException(string &&message) : AllocAddressException(
        message) {}


const char *vl::server::AddressPoolFullException::what() const noexcept {
    return AllocAddressException::what();
}

