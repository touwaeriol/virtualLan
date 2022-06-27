//
// Created by touwaerio on 2022/6/14.
//

#include "network/staticDataPackage.h"


namespace vl::core {
    using namespace std;


    //创建心跳包
    vector<Byte> heartBeatPackage() noexcept;

    //心跳数据包
    [[maybe_unused]] const vector<Byte> HEART_BEAT_PACKAGE = heartBeatPackage();


    vector<Byte> heartBeatPackage() noexcept {
        vector<Byte> data = vector<Byte>();
        data.resize(VL_HEART_BEAT_PACKAGE_SIZE);
        return move(data);
    }

}