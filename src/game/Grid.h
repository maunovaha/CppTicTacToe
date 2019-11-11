#ifndef GRID_H
#define GRID_H

#include "GridSlot.h"
#include <vector>
#include <string>
#include <utility>

namespace game {

using Grid2dRow = std::vector<GridSlot>;
using Grid2d = std::vector<Grid2dRow>;

class Grid {
public:
    Grid(const int size);
    void render() const;
    bool try_place(const int slot, const Chip& chip);
    bool is_full() const;
    const GridSlot& get_slot(const int row, const int column) const;

    inline int size() const
    {
        return size_;
    }

    inline int ending_slot() const
    {
        return size_ * size_;
    }

    constexpr static int starting_slot()
    {
        return starting_slot_;
    }
private:
    Grid2d setup_grid(const int size) const;
    std::pair<int, int> slot_to_row_and_column(const int slot) const;
    std::string to_ascii() const;

    Grid2d grid_;
    int size_ = 0;

    constexpr static int starting_slot_ = 1;
};

}

#endif