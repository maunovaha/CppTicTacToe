#include "GridSlot.h"

GridSlot::GridSlot(const int slot) : chip_{slot}
{
}

bool GridSlot::try_place(const Chip& chip)
{
    const bool free_slot = is_free();

    if (free_slot) {
        chip_ = chip;
    }

    return free_slot;
}

bool GridSlot::is_free() const
{
    return chip_.is_number();
}

std::ostream& operator <<(std::ostream& os, const GridSlot& other)
{
    os << other.chip_;
    return os;
}