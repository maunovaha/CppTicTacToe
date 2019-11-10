#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GridSlot.h"
#include <vector>
#include <string>
#include <utility>

using GridRow = std::vector<GridSlot>;
using Grid = std::vector<GridRow>;

class Gameboard {
public:
    Gameboard(const int size);
    void render() const;
    bool try_place(const int selected_slot, const Chip& chip);

    constexpr static int get_starting_slot()
    {
        return starting_slot_;
    }

    inline int get_ending_slot() const
    {
        return size_ * size_;
    }
private:
    Grid setup_grid(const int size) const;
    GridSlot& get_grid_slot(const int selected_slot);
    std::pair<int, int> selected_slot_to_row_and_column(const int selected_slot) const;
    std::string to_ascii() const;

    constexpr static int starting_slot_ = 1;

    Grid grid_;
    int size_ = 0;
};

#endif