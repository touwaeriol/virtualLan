//
// Created by touwaerio on 2022/5/29.
//

#ifndef VIRTUALLAN_AUTORELEASEMUTEX_H
#define VIRTUALLAN_AUTORELEASEMUTEX_H

#include "co/co.h"

namespace vl::core {

    template<typename T>
    class AutoReleaseMutex final {


    public:
        AutoReleaseMutex(T * mutex) : _mutex(mutex) {
            _mutex->lock();
        }

         ~AutoReleaseMutex() {
            _mutex->unlock();
        }

        void release(){
            _mutex->unlock();
            _mutex = nullptr;
        }


    private:
        T  * _mutex;
    };
}


#endif //VIRTUALLAN_AUTORELEASEMUTEX_H
