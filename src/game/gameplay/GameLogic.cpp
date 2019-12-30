#include "GameLogic.h"
#include "Grid.h"
#include "ChipType.h"
#include "../gameover/GameOverScene.h"
#include "../../engine/core/AppContext.h"
#include <cassert>
#include <vector>

namespace game::gameplay {

using namespace engine;
using namespace shared;

const Player& GameLogic::getCurrentPlayer() const
{
    return players_.at(currentPlayerIndex_);
}

void GameLogic::checkGameStatus(Grid* grid)
{
    assert(grid);

    const ChipType& currentPlayerChipType = getCurrentPlayer().getChipType();

    if (isWinningPattern(grid->toBinary(currentPlayerChipType))) {
        auto winner = std::make_unique<Player>(currentPlayerChipType);
        auto gameOverScene = std::make_unique<gameover::GameOverScene>(std::move(winner));
        core::AppContext::getDirector().play(std::move(gameOverScene));
    }
    else if (grid->isFull()) {
        core::AppContext::getDirector().play(std::make_unique<gameover::GameOverScene>());
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
