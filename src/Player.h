#ifndef PLAYER_H
#define PLAYER_H

#include "Gameboard.h"
#include <string>

class Player {
public:
    Player(const char chip);
    void update(Gameboard& gameboard) const;
private:
    std::string chip_;
};

#endif