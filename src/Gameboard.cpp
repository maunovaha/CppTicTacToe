#include "Gameboard.h"
#include "StringFormatter.h"
#include <iostream>
#include <sstream>
#include <cassert>

Gameboard::Gameboard(const int size) : grid_{setup_grid(size)}, size_{size}
{
}

void Gameboard::render() const
{
    std::cout << to_ascii();
}

bool Gameboard::try_place(const int selected_slot, const std::string& chip)
{
    assert(selected_slot >= get_starting_slot() && selected_slot <= get_ending_slot());

    return get_grid_slot(selected_slot).try_place(chip);
}

Grid Gameboard::setup_grid(const int size) const
{
    int current_slot = starting_slot_;
    Grid grid;

    for (int row = 0; row < size; ++row) {
        GridRow grid_row;

        for (int column = 0; column < size; ++column) {
            grid_row.emplace_back(current_slot++);
        }

        grid.emplace_back(grid_row);
    }

    return grid;
}

GridSlot& Gameboard::get_grid_slot(const int selected_slot)
{
    const std::pair<int, int> row_and_column = selected_slot_to_row_and_column(selected_slot);
    const int row = row_and_column.first;
    const int column = row_and_column.second;

    return grid_.at(row).at(column);
}

std::pair<int, int> Gameboard::selected_slot_to_row_and_column(const int selected_slot) const
{
    const int row = (selected_slot - starting_slot_) / size_;
    const int column = (selected_slot - starting_slot_) % size_;

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
std::string Gameboard::to_ascii() const
{
    std::ostringstream stream;

    stream << StringFormatter::repeat(" _____", size_) << "\n";

    for (int row = 0; row < size_; ++row) {
        stream << StringFormatter::repeat("|     ", size_) << "|\n";

        for (const auto& grid_slot : grid_.at(row)) {
            stream << "|  " << grid_slot << "  ";
        }

        stream << "|\n" + StringFormatter::repeat("|_____", size_) << "|\n";
    }

    stream << "\n";

    return stream.str();
}
