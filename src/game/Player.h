#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "Grid.h"
#include "Chip.h"
#include <string>
#include <ostream>

namespace game {

class Player {
public:
    Player(const std::string name, const Chip& chip);
    void update(Grid& grid) const;

    inline const Chip& get_chip() const
    {
        return chip_;
    }

    friend std::ostream& operator <<(std::ostream& os, const Player& other);
private:
    std::string name_;
    Chip chip_;
};

}

#endif