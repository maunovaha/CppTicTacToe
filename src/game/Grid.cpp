#include "Grid.h"
#include "../util/StringUtil.h"
#include <iostream>
#include <sstream>
#include <cassert>

namespace game {

Grid::Grid(const int size) : grid_{setup_grid(size)}, size_{size}
{
}

void Grid::render() const
{
    std::cout << to_ascii();
}

bool Grid::try_place(const int slot, const Chip& chip)
{
    assert(slot >= starting_slot() && slot <= ending_slot());

    const std::pair<int, int> row_and_column = slot_to_row_and_column(slot);
    const int row = row_and_column.first;
    const int column = row_and_column.second;

    return grid_.at(row).at(column).try_place(chip);
}

Grid2d Grid::setup_grid(const int size) const
{
    int current_slot = starting_slot_;
    Grid2d grid;

    for (int row = 0; row < size; ++row) {
        Grid2dRow grid_row;

        for (int column = 0; column < size; ++column) {
            grid_row.emplace_back(current_slot++);
        }

        grid.emplace_back(grid_row);
    }

    return grid;
}

std::pair<int, int> Grid::slot_to_row_and_column(const int slot) const
{
    const int row = (slot - starting_slot_) / size_;
    const int column = (slot - starting_slot_) % size_;

    return std::make_pair(row, column);
}

// Returns ascii representation of the gameboard.
//  _____ _____ _____ 
// |     |     |     |
// |  1  |  2  |  X  |
// |_____|_____|_____|
// |     |     |     |
// |  4  |  X  |  6  |
// |_____|_____|_____|
// |     |     |     |
// |  X  |  8  |  9  |
// |_____|_____|_____|
std::string Grid::to_ascii() const
{
    std::ostringstream stream;

    stream << util::StringUtil::repeat(" _____", size_) << "\n";

    for (int row = 0; row < size_; ++row) {
        stream << util::StringUtil::repeat("|     ", size_) << "|\n";

        for (const auto& grid_slot : grid_.at(row)) {
            stream << "|  " << grid_slot << "  ";
        }

        stream << "|\n" + util::StringUtil::repeat("|_____", size_) << "|\n";
    }

    stream << "\n";

    return stream.str();
}

}
