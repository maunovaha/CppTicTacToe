#include "GameplayScene.h"
#include "Grid.h"
#include <memory>

namespace game::gameplay {

using namespace engine;

void GameplayScene::onCreate()
{
    createGrid(math::Point{50, 50});
}

void GameplayScene::createGrid(const math::Point& position)
{
    std::unique_ptr<Grid> gridObj = std::make_unique<Grid>(position);

    addChild(std::move(gridObj));
}

}