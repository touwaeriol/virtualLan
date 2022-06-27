//
// Created by touwaerio on 2022/5/19.
//

#include <array>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>



#include "util/RequestIdGenerator.h"
#include <util/strUtil.h>

vl::core::RequestIdGenerator::RequestIdGenerator() : _generator(boost::uuids::random_generator_mt19937()) {


}


vl::core::RequestIdGenerator::~RequestIdGenerator() {

}

string vl::core::RequestIdGenerator::next() {
    auto uuid = _generator();
    return vl::core::replace(to_string(uuid), "-", "");
}




