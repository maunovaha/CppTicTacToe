#pragma once

#include "Player.h"
#include "../../engine/scene/GameObject.h"
#include <vector>
#include <array>

namespace game::gameplay {

class Grid; // Forward declaration
class GameLogic : public engine::scene::GameObject {
public:
    GameLogic(std::vector<Player> players) 
        : engine::scene::GameObject{"GameLogic"}, players_{std::move(players)} {}
    const Player& getCurrentPlayer() const;
    void checkGameStatus(Grid* grid);
private:
    bool isWinningPattern(const uint16_t pattern);
    void changePlayerTurn();

    std::vector<Player> players_;
    unsigned int currentPlayerIndex_ = 0;

    // There are 8 different winning combinations when having 3x3 grid. For more information on
    // how these bits are mapped to grid read the code comments of Grid::toBinary() function.
    static constexpr std::array<uint16_t, 8> WINNING_PATTERNS = {
        0b0000'0001'1100'0000,
        0b0000'0000'0011'1000,
        0b0000'0000'0000'0111,
        0b0000'0001'0010'0100,
        0b0000'0000'1001'0010,
        0b0000'0000'0100'1001,
        0b0000'0001'0001'0001,
        0b0000'0000'0101'0100,
    };
};

}
