//
// Created by touwaerio on 2022/5/19.
//

#ifndef VIRTUALLAN_CORE_H
#define VIRTUALLAN_CORE_H



#include <grpcpp/grpcpp.h>

#include <concurrentqueue.h>
#include <blockingconcurrentqueue.h>
#include <readerwriterqueue.h>
#include <readerwritercircularbuffer.h>

#include <cstdint>
#include <cstdlib>


#include <tbb/tbb.h>

#include <asio.hpp>

#include "core/log/consoleLog.h"
#include "core/rpc/RegisterService.grpc.pb.h"

#include "core/network/address.h"
#include "core/network/Tap.h"
#include "core/network/EthernetV2Frame.h"
#include "core/network/staticDataPackage.h"


#include "core/util/define.h"
#include "core/util/typeDefile.h"
#include "core/util/RequestIdGenerator.h"
#include "core/util/Uncopymovable.hpp"

#include "core/exception/exception.h"


#include "thread/ThreadPool.h"



#endif //VIRTUALLAN_CORE_H
