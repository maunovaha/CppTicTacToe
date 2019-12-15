#include "MainMenuScene.h"
#include "../../engine/sprite/SpriteSheet.h"
#include "../../engine/ui/Text.h"

namespace game::mainmenu {

using namespace engine;

void MainMenuScene::create(const gfx::Window& window, gfx::TextureCache& textureCache)
{
    const sprite::SpriteSheet spriteSheet = {
        window.getRenderer(),
        textureCache,
        "assets/textures/SpriteSheet.png",
        {
            {"background", std::make_shared<sprite::SpriteClip>(0, 0, 360, 360)},
            {"x",          std::make_shared<sprite::SpriteClip>(360, 0, 120, 120)},
            {"o",          std::make_shared<sprite::SpriteClip>(360, 120, 120, 120)}
        }
    };

    const std::shared_ptr<sprite::Sprite> background = spriteSheet.getSprite("background");
    background->setPosition(50, 50);
    addChild(background);

    const std::shared_ptr<sprite::Sprite> x = spriteSheet.getSprite("x");
    x->setPosition(50, 50);
    addChild(x);

    const std::shared_ptr<sprite::Sprite> o = spriteSheet.getSprite("o");
    o->setPosition(170, 170);
    addChild(o);

    const std::shared_ptr<ui::Font> font = std::make_shared<ui::Font>(
        "assets/fonts/PermanentMarker-Regular.ttf", 44);

    const std::shared_ptr<ui::Text> text = std::make_shared<ui::Text>("Hello World", font,
        ui::Color{0x00, 0x00, 0x00, 0xFF}, 0, 0, window.getRenderer());

    addChild(text);
}

void MainMenuScene::update()
{
}

}