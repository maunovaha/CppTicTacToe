#ifndef PLAYER_H
#define PLAYER_H

#include "Gameboard.h"
#include "Chip.h"
#include <string>

class Player {
public:
    Player(const std::string name, const Chip& chip);
    void update(Gameboard& gameboard) const;
private:
    std::string name_;
    Chip chip_;
};

#endif