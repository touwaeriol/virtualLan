//
// Created by touwaerio on 2022/5/19.
//

#include <array>
#include "util/RequestIdGenerator.h"
#include <uuid.h>


vl::core::RequestIdGenerator::RequestIdGenerator(std::mt19937 generator) : _generator(
        uuids::uuid_random_generator(generator)) {

}


vl::core::RequestIdGenerator::~RequestIdGenerator() {

}

string vl::core::RequestIdGenerator::next() {
    return to_string(_generator());
}

 vl::core::RequestIdGenerator vl::core::RequestIdGenerator::defaultGenerator() {
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size>{};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    std::mt19937 generator(seq);
    return {generator};
}