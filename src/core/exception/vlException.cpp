//
// Created by touwaerio on 2022/5/20.
//

#ifndef VIRTUALLAN_VLEXCEPTION_CPP
#define VIRTUALLAN_VLEXCEPTION_CPP

#include <stdexcept>
#include <boost/exception/exception.hpp>
namespace vl::core{
class VlException : public virtual std::exception , public virtual boost::exception{

    public:

        ~VlException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = 0;

        const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override = 0;


    };
}




#endif //VIRTUALLAN_VLEXCEPTION_CPP
