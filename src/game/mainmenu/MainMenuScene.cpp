#include "MainMenuScene.h"
#include "../../engine/sprite/SpriteSheet.h"
#include "../../engine/ui/Text.h"
#include "../../engine/ui/Button.h"

/////////// TEMP
#include <iostream>

namespace game::mainmenu {

using namespace engine;

void MainMenuScene::onCreate(const gfx::Window& window, gfx::TextureCache& textureCache)
{
    const sprite::SpriteSheet spriteSheet = {
        window.getRenderer(),
        textureCache,
        "assets/textures/SpriteSheet.png",
        {
            {"background", std::make_shared<sprite::SpriteClip>(0, 0, 360, 360)},
            {"x",          std::make_shared<sprite::SpriteClip>(360, 0, 120, 120)},
            {"o",          std::make_shared<sprite::SpriteClip>(360, 120, 120, 120)},
            {"button",     std::make_shared<sprite::SpriteClip>(360, 245, 178, 65)}
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

    const std::shared_ptr<ui::Font> titleFont = std::make_shared<ui::Font>(
        "assets/fonts/PermanentMarker-Regular.ttf", 44
    );
    const std::shared_ptr<ui::Text> text = std::make_shared<ui::Text>(
        "Hello World", titleFont, ui::Color{0x00, 0x00, 0x00, 0xFF}, 0, 0, window.getRenderer()
    );
    addChild(text);

    const std::shared_ptr<ui::Font> buttonFont = std::make_shared<ui::Font>(
        "assets/fonts/LilitaOne-Regular.ttf", 24
    );
    const std::shared_ptr<ui::Button> testButton = std::make_shared<ui::Button>(
        "PLAY AGAIN", buttonFont, ui::Color{0x00, 0x00, 0x00, 0xFF},
        spriteSheet.getSprite("button"), 
        100, 100,
        window.getRenderer()
    );

    testButton->registerOnClickListener([]() -> void {
        std::cout << "Button clicked!\n";
    });

    addChild(testButton);
}

void MainMenuScene::onUpdate()
{
}

}