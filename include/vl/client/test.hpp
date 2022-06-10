//
// Created by touwaerio on 2022/6/1.
//

#ifndef VIRTUALLAN_TEST_HPP
#define VIRTUALLAN_TEST_HPP

#include <co/all.h>
#include <vl/core.h>

DEF_test(tap){

    DEF_case(create){
        using namespace vl::core;

        auto tap = std::make_unique<Tap>();

        tap->ip("10.10.1.1", 24);

        tap->name("vl-adapter0");
        tap->up();

    }

}

#endif //VIRTUALLAN_TEST_HPP
