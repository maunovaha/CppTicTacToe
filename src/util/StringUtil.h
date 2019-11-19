#ifndef UTIL_STRING_UTIL_H
#define UTIL_STRING_UTIL_H

#include <string>

namespace util {

class StringUtil {
public:
    StringUtil() = delete;
    static std::string repeat(const std::string& value, const int times);
};

}

#endif