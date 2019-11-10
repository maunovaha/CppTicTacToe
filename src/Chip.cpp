#include "Chip.h"
#include <utility>

Chip::Chip(const std::string value) : value_{std::move(value)}
{
}

Chip::Chip(const int value) : Chip{std::to_string(value)}
{
}

std::ostream& operator <<(std::ostream& os, const Chip& other)
{
    os << other.value_;
    return os;
}
