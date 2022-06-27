
//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_UNCOPYMOVABLE_HPP
#define VIRTUALLAN_UNCOPYMOVABLE_HPP

#include "Uncopyable.hpp"
#include "Unmovable.hpp"

namespace vl::core {
    class Uncopymovable : public Uncopyable, public Unmovable {
    public:
        Uncopymovable() = default;

        ~Uncopymovable() override {};

    private:


    };
}

#endif //VIRTUALLAN_UNCOPYMOVABLE_HPP
