#ifndef GRID_SLOT_H
#define GRID_SLOT_H

#include <ostream>
#include <string>

class GridSlot {
public:
    GridSlot(const int chip);
    friend std::ostream& operator <<(std::ostream& os, const GridSlot& other);
private:
    std::string chip_;
};

#endif