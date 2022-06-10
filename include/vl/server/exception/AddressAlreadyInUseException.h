
//
// Created by touwaerio on 2022/5/29.
//

#ifndef VIRTUALLAN_ADDRESSALREADYINUSEEXCEPTION_H
#define VIRTUALLAN_ADDRESSALREADYINUSEEXCEPTION_H

#include "AllocAddressException.h"

namespace vl::server{

    class AddressAlreadyInUseException :public AllocAddressException{


    public:
        AddressAlreadyInUseException(const string &message);

        AddressAlreadyInUseException(string &&message);

        ~AddressAlreadyInUseException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = default;

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

    };
}




#endif //VIRTUALLAN_ADDRESSALREADYINUSEEXCEPTION_H
