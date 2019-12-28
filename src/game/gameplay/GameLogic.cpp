#include "GameLogic.h"

namespace game::gameplay {

using namespace engine;

const Player& GameLogic::getCurrentPlayer() const
{
    return players_.at(currentPlayerIndex_);
}

void GameLogic::changePlayerTurn()
{
    ++currentPlayerIndex_;

    if (currentPlayerIndex_ >= players_.size()) {
        currentPlayerIndex_ = 0;
    }

    // This might be stupid, but since this method is called whenever new chip
    // is placed on the grid, we might as well call checking of game status here as well.
    checkGameStatus();
}

void GameLogic::checkGameStatus()
{
    // TODO: Check win/lose/draw ..
}

}
