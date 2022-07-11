//
// Created by touwaerio on 2022/5/19.
//

#ifndef VIRTUALLAN_CORE_H
#define VIRTUALLAN_CORE_H

#include <grpcpp/grpcpp.h>
#include <gflags/gflags.h>
#include <gtest/gtest.h>

#include <concurrentqueue.h>
#include <blockingconcurrentqueue.h>
#include <readerwriterqueue.h>
#include <readerwritercircularbuffer.h>


#include <oneapi/tbb.h>

#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/exception/exception.hpp>

#include <fmt/format.h>

#include <async++.h>

#include "core/log/log.h"

#include "core/rpc/RegisterService.grpc.pb.h"

#include "core/etnernet/address.h"
#include "core/etnernet/Tap.h"
#include "core/etnernet/EthernetV2Frame.h"
#include "core/etnernet/staticDataPackage.h"
#include "core/etnernet/EtherData.h"


#include "core/util/define.h"
#include "core/util/typeDefile.h"
#include "core/util/RequestIdGenerator.h"
#include "core/util/Uncopymovable.hpp"
#include "core/util/strUtil.h"
#include "core/exception/exception.h"


#include "thread/ThreadPool.h"


#endif //VIRTUALLAN_CORE_H
