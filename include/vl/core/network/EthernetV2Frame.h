//
// Created by touwaerio on 2022/5/23.
//

#ifndef VIRTUALLAN_ETHERNETV2FRAME_H
#define VIRTUALLAN_ETHERNETV2FRAME_H

#include "Frame.h"

namespace vl::core {

    template<int MTU>
    class EthernetV2Frame;


}


namespace vl::core {
    
    template<int MTU>
    class EthernetV2Frame : public Frame<MTU> {

    };


}


#endif //VIRTUALLAN_ETHERNETV2FRAME_H
