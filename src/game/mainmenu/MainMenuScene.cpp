#include "MainMenuScene.h"
#include "../../engine/Sprite.h"

namespace game::mainmenu {

void MainMenuScene::create(const engine::Window& window, engine::TextureCache& textureCache)
{
    // Note: The current asset path wont probably work with Mac, but will be fixed later on.

    const std::shared_ptr<engine::Sprite> s1 = std::make_shared<engine::Sprite>(window.getRenderer(), 
        textureCache,
        "assets/textures/120x120.png");

    const std::shared_ptr<engine::Sprite> s2 = std::make_shared<engine::Sprite>(window.getRenderer(),
        textureCache,
        "assets/textures/120x120.png", 120, 120);

    const std::shared_ptr<engine::Sprite> s3 = std::make_shared<engine::Sprite>(window.getRenderer(),
        textureCache,
        "assets/textures/120x120.png", 240, 240);

    addChild(s1);
    addChild(s2);
    addChild(s3);
}

void MainMenuScene::update()
{
}

}