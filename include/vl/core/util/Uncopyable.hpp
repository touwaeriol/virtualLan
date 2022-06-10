//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_UNCOPYABLE_HPP
#define VIRTUALLAN_UNCOPYABLE_HPP

namespace vl::core {
    class Uncopyable {
    public:
        Uncopyable() = default;

        virtual ~Uncopyable()  {};

    private:
        Uncopyable(const Uncopyable &) = delete;

        Uncopyable &operator=(const Uncopyable &) = delete;
    };
}

#endif //VIRTUALLAN_UNCOPYABLE_HPP
