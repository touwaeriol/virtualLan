//
// Created by touwaerio on 2022/6/21.
//

#ifndef VIRTUALLAN_STRUTIL_H
#define VIRTUALLAN_STRUTIL_H


#include <cstdarg>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>

namespace vl::core {

    std::vector<std::string> compact(const std::vector<std::string> &tokens);

    std::vector<std::wstring> compact(const std::vector<std::wstring> &tokens);

    std::vector<std::string>
    split(const std::string &str, const std::string &delim, const bool trim_empty = false);

    std::vector<std::wstring>
    split(const std::wstring &str, const std::wstring &delim, const bool trim_empty = false);

    std::string
    join(const std::vector<std::string> &tokens, const std::string &delim, const bool trim_empty = false);


    std::wstring
    join(const std::vector<std::wstring> &tokens, const std::wstring &delim, const bool trim_empty = false);


    std::string trim(const std::string &str);

    std::wstring trim(const std::wstring &str);

    std::string repeat(const std::string &str, unsigned int times);

    std::wstring repeat(const std::wstring &str, unsigned int times);

    std::string Toupper(const std::string &str);

    std::wstring Toupper(const std::wstring &str);

    std::string Tolower(const std::string &str);

    std::wstring Tolower(const std::wstring &str);

    std::string
    replace(const std::string &source, const std::string &target, const std::string &replacement);

    std::wstring
    replace(const std::wstring &source, const std::wstring &target, const std::wstring &replacement);

    std::string between(const std::string &str, const std::string &left, const std::string &right);

    std::wstring between(const std::wstring &str, const std::wstring &left, const std::wstring &right);

    std::vector<std::string>
    between_array(const std::string &str, const std::string &left, const std::string &right,
                  const bool trim_empty = false);

    std::vector<std::wstring>
    between_array(const std::wstring &str, const std::wstring &left, const std::wstring &right,
                  const bool trim_empty = false);

    std::string left(const std::string &str, const std::string &left);

    std::wstring left(const std::wstring &str, const std::wstring &left);

    std::string right(const std::string &str, const std::string &right);

    std::wstring right(const std::wstring &str, const std::wstring &right);

    bool is_start_with(const std::string &str, const std::string &src);

    bool is_start_with(const std::wstring &str, const std::wstring &src);

    bool is_end_with(const std::string &str, const std::string &src);

    bool is_end_with(const std::wstring &str, const std::wstring &src);

};


#endif //VIRTUALLAN_STRUTIL_H
