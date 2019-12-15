#include "MainMenuScene.h"
#include "../../engine/sprite/SpriteSheet.h"
// #include "../../engine/ui/Text.h"

namespace game::mainmenu {

void MainMenuScene::create(const engine::gfx::Window& window, engine::gfx::TextureCache& textureCache)
{
    const engine::sprite::SpriteSheet spriteSheet = {
        window.getRenderer(),
        textureCache,
        "assets/textures/SpriteSheet.png",
        {
            {"background", std::make_shared<engine::sprite::SpriteClip>(0, 0, 360, 360)},
            {"x",          std::make_shared<engine::sprite::SpriteClip>(360, 0, 120, 120)},
            {"o",          std::make_shared<engine::sprite::SpriteClip>(360, 120, 120, 120)}
        }
    };

    const std::shared_ptr<engine::sprite::Sprite> background = spriteSheet.getSprite("background");
    background->setPosition(50, 50);
    addChild(background);

    const std::shared_ptr<engine::sprite::Sprite> x = spriteSheet.getSprite("x");
    x->setPosition(50, 50);
    addChild(x);

    const std::shared_ptr<engine::sprite::Sprite> o = spriteSheet.getSprite("o");
    o->setPosition(170, 170);
    addChild(o);

    //const std::shared_ptr<engine::ui::Font> font = std::make_shared<engine::ui::Font>(
    //    "assets/fonts/PermanentMarker-Regular.ttf", 44);

    //const std::shared_ptr<engine::ui::Text> text = std::make_shared<engine::ui::Text>(
    //    window.getRenderer(), font, "Hello World", SDL_Color{0x00, 0x00, 0x00, 0xFF});

    //addChild(text);
}

void MainMenuScene::update()
{
}

}