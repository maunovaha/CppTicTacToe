#ifndef STRING_FORMATTER_H
#define STRING_FORMATTER_H

#include <string>

class StringFormatter {
public:
    StringFormatter() = delete;
    static std::string repeat(const std::string& pattern, const int times);
};

#endif