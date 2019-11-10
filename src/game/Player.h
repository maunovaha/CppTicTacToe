#ifndef PLAYER_H
#define PLAYER_H

#include "Grid.h"
#include "Chip.h"
#include <string>
#include <ostream>

namespace game {

class Player {
public:
    Player(const std::string name, const Chip& chip);
    void update(Grid& grid) const;

    // inline std::string chip() const
    // {
    //     return chip_.value();
    // }

    friend std::ostream& operator <<(std::ostream& os, const Player& other);
private:
    std::string name_;
    Chip chip_;
};

}

#endif