//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_VLEXCEPTION_H
#define VIRTUALLAN_VLEXCEPTION_H

#include <stdexcept>

namespace vl::core {
    class VlException : public std::exception {

    public:

        ~VlException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = default;

        [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = 0;


    };
}


#endif //VIRTUALLAN_VLEXCEPTION_H
