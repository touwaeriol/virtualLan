//
// Created by touwaerio on 2022/5/29.
//

#ifndef VIRTUALLAN_ALLOCADDRESSEXCEPTION_H
#define VIRTUALLAN_ALLOCADDRESSEXCEPTION_H

#include  "vl/core.h"

namespace vl::server {
    class AllocAddressException : vl::core::VlException {

    public:

        AllocAddressException(const string &message);

        AllocAddressException(string &&message);

        ~AllocAddressException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = default;

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;


    private:
        std::string message;

    };

}


#endif //VIRTUALLAN_ALLOCADDRESSEXCEPTION_H
