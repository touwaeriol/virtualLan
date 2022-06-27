//
// Created by touwaerio on 2022/5/29.
//

#ifndef VIRTUALLAN_ADDRESSPOOLFULLEXCEPTION_H
#define VIRTUALLAN_ADDRESSPOOLFULLEXCEPTION_H

#include "AllocAddressException.h"

namespace vl::server{

    class AddressPoolFullException: public AllocAddressException{

    public:

        AddressPoolFullException(const string &message);

        AddressPoolFullException(string &&message);

        ~AddressPoolFullException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = default;

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

    };
}



#endif //VIRTUALLAN_ADDRESSPOOLFULLEXCEPTION_H
