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
            {"o",          std::make_shared<engine::SpriteClip>(360, 360, 120, 120)}
        }
    };

    const std::shared_ptr<engine::Sprite> background = spriteSheet.getSprite("background");
    const std::shared_ptr<engine::Sprite> x = spriteSheet.getSprite("x");
    const std::shared_ptr<engine::Sprite> o = spriteSheet.getSprite("o");

    addChild(background);
    addChild(x);
    addChild(o);
}

void MainMenuScene::update()
{
}

}