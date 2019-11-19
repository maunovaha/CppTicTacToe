#ifndef GAME_GRID_SLOT_H
#define GAME_GRID_SLOT_H

#include "Chip.h"
#include <ostream>

namespace game {

class GridSlot {
public:
    GridSlot(const int slot);
    bool try_place(const Chip& chip);
    bool is_free() const;
    friend std::ostream& operator <<(std::ostream& os, const GridSlot& other);
    
    /* explicit */ inline operator std::string() const
    {
        return chip_;
    }
private:
    Chip chip_;
};

}

#endif