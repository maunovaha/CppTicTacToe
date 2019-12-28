#pragma once

#include "Player.h"
#include "../../engine/scene/GameObject.h"
#include <vector>

namespace game::gameplay {

class GameLogic : public engine::scene::GameObject {
public:
    GameLogic(std::vector<Player> players) 
        : engine::scene::GameObject{"GameLogic"}, players_{std::move(players)} {}
    const Player& getCurrentPlayer() const;
    void changePlayerTurn();
private:
    void checkGameStatus();
    
    std::vector<Player> players_;
    unsigned int currentPlayerIndex_ = 0;
};

}
