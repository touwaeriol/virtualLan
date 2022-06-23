
//
// Created by touwaerio on 2022/5/19.
//

#ifndef VIRTUALLAN_REQUESTIDGENERATOR_H
#define VIRTUALLAN_REQUESTIDGENERATOR_H

#include <string>
#include <sstream>
#include <memory>
#include <uuid.h>

using namespace std;


namespace vl::core {
    class RequestIdGenerator {

    public:

        RequestIdGenerator(const RequestIdGenerator &uuid) = default;

        RequestIdGenerator(RequestIdGenerator &&uuid) = default;


        ~ RequestIdGenerator();

        RequestIdGenerator &operator=(RequestIdGenerator &&uuid) = default;

        RequestIdGenerator &operator=(const RequestIdGenerator &uuid) = default;

        std::string next();

        /**
         * 默认构建器
         * @return
         */
        static RequestIdGenerator defaultGenerator();


    private:
        uuids::uuid_random_generator _generator;

        /**
         * 内部构造函数防止使用
         * @param generator
         */
        RequestIdGenerator(std::mt19937 generator);
    };

}


#endif //VIRTUALLAN_REQUESTIDGENERATOR_H
