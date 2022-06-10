
//
// Created by touwaerio on 2022/5/29.
//

#ifndef VIRTUALLAN_ADDRESSERRORFORMATEXCEPTION_H
#define VIRTUALLAN_ADDRESSERRORFORMATEXCEPTION_H

#include "AllocAddressException.h"

namespace vl::server{

    class AddressErrorFormatException : public AllocAddressException{

    public:

        AddressErrorFormatException(const string &message);

        AddressErrorFormatException(string &&message);

        ~AddressErrorFormatException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = default;

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

    };


}


#endif //VIRTUALLAN_ADDRESSERRORFORMATEXCEPTION_H
