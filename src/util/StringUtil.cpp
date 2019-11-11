#include "StringUtil.h"

namespace util {

std::string StringUtil::repeat(const std::string& value, const int times)
{
    std::string repeated_value = value;

    for (int i = 0; i < (times - 1); ++i) {
        repeated_value += value;
    }

    return repeated_value;
}

}