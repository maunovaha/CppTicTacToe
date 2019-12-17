#include "GameplayScene.h"

namespace game::gameplay {

using namespace engine::core;
using namespace engine::sprite;
using namespace engine::ui;

void GameplayScene::onCreate()
{
    loadSpriteSheet();
}

void GameplayScene::loadSpriteSheet()
{
    spriteSheet_ = std::make_unique<SpriteSheet>(
        "assets/textures/SpriteSheet.png", SpriteSheet::Config{
            {"grid", std::make_shared<SpriteSheet::SpriteClip>(0, 0, 360, 360)},
            {"x",    std::make_shared<SpriteSheet::SpriteClip>(360, 0, 120, 120)},
            {"o",    std::make_shared<SpriteSheet::SpriteClip>(360, 120, 120, 120)}
        }
    );
}

void GameplayScene::onUpdate()
{
}

}