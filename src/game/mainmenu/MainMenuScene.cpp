#include "MainMenuScene.h"
#include "../../engine/SpriteSheet.h"

namespace game::mainmenu {

void MainMenuScene::create(const engine::Window& window, engine::TextureCache& textureCache)
{
    const engine::SpriteSheet spriteSheet = {
        window.getRenderer(),
        textureCache,
        "assets/textures/SpriteSheet.png",
        {
            {"background", std::make_shared<engine::SpriteClip>(0, 0, 360, 360)},
            {"x",          std::make_shared<engine::SpriteClip>(360, 0, 120, 120)},
            {"o",          std::make_shared<engine::SpriteClip>(360, 120, 120, 120)}
        }
    };

    const std::shared_ptr<engine::Sprite> background = spriteSheet.getSprite("background");
    background->setPosition(50, 50);
    addChild(background);

    const std::shared_ptr<engine::Sprite> x = spriteSheet.getSprite("x");
    x->setPosition(50, 50);
    addChild(x);

    const std::shared_ptr<engine::Sprite> o = spriteSheet.getSprite("o");
    o->setPosition(170, 170);
    addChild(o);
}

void MainMenuScene::update()
{
}

}