#ifndef PLAYER_H
#define PLAYER_H

#include "Gameboard.h"
#include <string>

class Player {
public:
    Player(const std::string name, const char chip);
    void update(Gameboard& gameboard) const;
private:
    std::string name_;
    std::string chip_;
};

#endif