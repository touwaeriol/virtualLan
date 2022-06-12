//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_VLSOCKETEXCEPTION_H
#define VIRTUALLAN_VLSOCKETEXCEPTION_H

#include <string>
#include "exception/VlException.h"


namespace vl::core{

    class VlSocketException : public VlException{

    public:
        VlSocketException(int errorCode, const std::string &errorMessage);
        VlSocketException(int errorCode,  std::string &&errorMessage);


        ~VlSocketException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

       [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;


    private:


        int errorCode;

        std::string  errorMessage;

        std::string message;


    };
}




#endif //VIRTUALLAN_VLSOCKETEXCEPTION_H
