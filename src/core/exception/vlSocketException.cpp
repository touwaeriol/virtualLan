//
// Created by touwaerio on 2022/5/20.
//



#ifndef VIRTUALLAN_VLSOCKETEXCEPTION_CPP
#define VIRTUALLAN_VLSOCKETEXCEPTION_CPP

#include <string>
#include "exception/VlSocketException.h"

vl::core::VlSocketException::VlSocketException(int errorCode, const std::string &errorMessage)
        : errorCode(errorCode),
          errorMessage(errorMessage),
          message("errorCode: " + std::to_string(errorCode) + " ,errorMessage: " + errorMessage) {}
vl::core::VlSocketException::VlSocketException(int errorCode,  std::string &&errorMessage)
        : errorCode(errorCode),
          errorMessage(errorMessage),
          message("errorCode: " + std::to_string(errorCode) + " ,errorMessage: " + errorMessage) {}

vl::core::VlSocketException::~VlSocketException() noexcept {

}

const char *vl::core::VlSocketException::what() const noexcept {
    return message.c_str();
}


#endif //VIRTUALLAN_VLSOCKETEXCEPTION_CPP


