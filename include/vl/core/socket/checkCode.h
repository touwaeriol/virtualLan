//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_CHECKCODE_H
#define VIRTUALLAN_CHECKCODE_H

#define CHECK_CODE(code)  \
    if(code == -1){ \
        auto errorCode = co::error();  \
        auto errorMessage = co::strerror(errorCode); \
        throw VlSocketException(errorCode, errorMessage); \
    }



#endif //VIRTUALLAN_CHECKCODE_H
