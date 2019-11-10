#include "GridSlot.h"

#include <iostream>

GridSlot::GridSlot(const int chip) : chip_{std::to_string(chip)}
{
}

bool GridSlot::try_place(const std::string& chip)
{
    // Check if is free..

    chip_ = chip;

    return true;
}

std::ostream& operator <<(std::ostream& os, const GridSlot& other)
{
    os << other.chip_;
    return os;
}