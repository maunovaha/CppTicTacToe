#include "StringFormatter.h"

std::string StringFormatter::repeat(const std::string& pattern, const int times)
{
    std::string repeated_pattern = pattern;

    for (int i = 0; i < (times - 1); ++i) {
        repeated_pattern += pattern;
    }

    return repeated_pattern;
}
