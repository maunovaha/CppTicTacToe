#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "GridSlot.h"
#include <vector>
#include <ostream>

using GridRow = std::vector<GridSlot>;
using Grid = std::vector<GridRow>;

class Gameboard {
public:
    Gameboard(const int size);
    void render() const;
    int size() const;
private:
    Grid create_grid(const int size) const;
    std::string to_ascii() const;

    constexpr static int starting_chip_ = 1;
    Grid grid_;
};

#endif