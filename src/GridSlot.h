#ifndef GRID_SLOT_H
#define GRID_SLOT_H

#include "Chip.h"
#include <ostream>

class GridSlot {
public:
    GridSlot(const int slot);
    bool try_place(const Chip& chip);
    friend std::ostream& operator <<(std::ostream& os, const GridSlot& other);
private:
    bool is_free() const;

    Chip chip_;
};

#endif