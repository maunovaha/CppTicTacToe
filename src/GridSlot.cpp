#include "GridSlot.h"

#include <iostream>

GridSlot::GridSlot(const int chip) : chip_{std::to_string(chip)}
{
}

std::ostream& operator <<(std::ostream& os, const GridSlot& other)
{
    os << other.chip_;
    return os;
}