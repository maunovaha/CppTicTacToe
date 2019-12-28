#include "GameplayScene.h"
#include "Grid.h"
#include "ChipType.h"
#include "GameLogic.h"
#include <memory>

namespace game::gameplay {

using namespace engine;

void GameplayScene::onCreate()
{
    createGrid(math::Point{50, 50}, 3);
    createGameLogic(createPlayers());
}

void GameplayScene::createGrid(const math::Point& position, const int size)
{
    addChild(std::make_unique<Grid>(position, size));
}

std::vector<Player> GameplayScene::createPlayers()
{
    return {
        Player{ChipType::X}, Player{ChipType::O}
    };
}

void GameplayScene::createGameLogic(std::vector<Player> players)
{
    addChild(std::make_unique<GameLogic>(std::move(players)));
}

}