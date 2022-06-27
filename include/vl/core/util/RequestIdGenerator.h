
//
// Created by touwaerio on 2022/5/19.
//

#ifndef VIRTUALLAN_REQUESTIDGENERATOR_H
#define VIRTUALLAN_REQUESTIDGENERATOR_H

#include <string>
#include <sstream>
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>


using namespace std;


namespace vl::core {
    class RequestIdGenerator {

    public:

        RequestIdGenerator();

        RequestIdGenerator(const RequestIdGenerator &uuid) = default;

        RequestIdGenerator(RequestIdGenerator &&uuid) = default;


        ~ RequestIdGenerator();

        RequestIdGenerator &operator=(RequestIdGenerator &&uuid) = default;

        RequestIdGenerator &operator=(const RequestIdGenerator &uuid) = default;

    public:

        std::string next();


    private:
        boost::uuids::random_generator_mt19937 _generator;


    };

}


#endif //VIRTUALLAN_REQUESTIDGENERATOR_H
