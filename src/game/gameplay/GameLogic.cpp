#include "GameLogic.h"
#include "Grid.h"
#include <cassert>

// 
#include <iostream>

namespace game::gameplay {

using namespace engine;

const Player& GameLogic::getCurrentPlayer() const
{
    return players_.at(currentPlayerIndex_);
}

void GameLogic::checkGameStatus(Grid* grid)
{
    assert(grid);

    if (isWinningPattern(grid->toBinary(getCurrentPlayer().getChipType()))) {
        std::cout << "------------------------------------\n";
        std::cout << "Game over!\n" << getCurrentPlayer().getName() << " wins!\n";
    }
    else if (grid->isFull()) {
        std::cout << "Draw!\n";
    }
    else {
        changePlayerTurn();
    }
}

bool GameLogic::isWinningPattern(const uint16_t pattern)
{
    for (const auto& winningPattern : WINNING_PATTERNS) {
        if ((pattern & winningPattern) == winningPattern) {
            return true;
        }
    }
    return false;
}

void GameLogic::changePlayerTurn()
{
    ++currentPlayerIndex_;

    if (currentPlayerIndex_ >= players_.size()) {
        currentPlayerIndex_ = 0;
    }
}

}
