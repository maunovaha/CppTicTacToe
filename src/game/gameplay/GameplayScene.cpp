#include "GameplayScene.h"

namespace game::gameplay {

using namespace engine::core;
using namespace engine::sprite;
using namespace engine::ui;

void GameplayScene::onCreate()
{
    createSpriteSheet();
    createGrid();
}

void GameplayScene::createSpriteSheet()
{
    spriteSheet_ = std::make_unique<SpriteSheet>(
        "assets/textures/SpriteSheet.png", SpriteSheet::Config{
            {"Grid", std::make_shared<SpriteSheet::SpriteClip>(0, 0, 360, 360)},
            {"X",    std::make_shared<SpriteSheet::SpriteClip>(360, 0, 120, 120)},
            {"O",    std::make_shared<SpriteSheet::SpriteClip>(360, 120, 120, 120)}
        }
    );
}

void GameplayScene::createGrid()
{
    grid_ = std::make_shared<Grid>(spriteSheet_->getSprite("Grid"), 50, 50);
    addChild(grid_);
}

}