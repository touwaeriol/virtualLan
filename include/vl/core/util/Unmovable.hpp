//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_UNMOVABLE_HPP
#define VIRTUALLAN_UNMOVABLE_HPP


namespace vl::core {
    class Unmovable {
    public:
        Unmovable() = default;

        virtual ~Unmovable() {};

    private:
        Unmovable(Unmovable &&) = delete;

        Unmovable &operator=(Unmovable &&) = delete;
    };


}
#endif //VIRTUALLAN_UNMOVABLE_HPP
