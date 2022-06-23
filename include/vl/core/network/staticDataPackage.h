//
// Created by touwaerio on 2022/6/14.
//

#ifndef VIRTUALLAN_STATICDATAPACKAGE_H
#define VIRTUALLAN_STATICDATAPACKAGE_H

#include <vector>
#include "util/typeDefile.h"


namespace vl::core {
    using namespace std;

#define VL_HEART_BEAT_PACKAGE_SIZE 1


    //心跳数据包
    [[maybe_unused]] extern const vector<Byte> HEART_BEAT_PACKAGE;


}


#endif //VIRTUALLAN_STATICDATAPACKAGE_H
