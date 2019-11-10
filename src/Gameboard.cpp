#include "Gameboard.h"
#include "StringFormatter.h"
#include <iostream>
#include <sstream>

Gameboard::Gameboard(const int size) : grid_{create_grid(size)}
{
}

Grid Gameboard::create_grid(const int size) const
{
    int chip = starting_chip_;
    Grid grid;

    for (int row = 0; row < size; ++row) {
        GridRow grid_row;

        for (int column = 0; column < size; ++column) {
            grid_row.emplace_back(chip++);
        }

        grid.emplace_back(grid_row);
    }

    return grid;
}

int Gameboard::size() const
{
    return grid_.size();
}

void Gameboard::render() const
{
    std::cout << to_ascii();
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
    const int times = size();
    std::ostringstream stream;

    stream << StringFormatter::repeat(" _____", times) << "\n";

    for (int row = 0; row < times; ++row) {
        stream << StringFormatter::repeat("|     ", times) << "|\n";

        for (const auto& grid_slot : grid_.at(row)) {
            stream << "|  " << grid_slot << "  ";
        }

        stream << "|\n" + StringFormatter::repeat("|_____", times) << "|\n";
    }

    stream << "\n";

    return stream.str();
}
