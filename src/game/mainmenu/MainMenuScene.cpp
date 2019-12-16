#include "MainMenuScene.h"
#include "../../engine/ui/Text.h"
#include "../../engine/ui/Button.h"

namespace game::mainmenu {

using namespace engine;

void MainMenuScene::onCreate(const gfx::Window& window, gfx::TextureCache& textureCache)
{
    loadSpriteSheet(window, textureCache);
    createTitleText(window);
    createSubtitleText(window);
    createStartButton(window);
}

void MainMenuScene::loadSpriteSheet(const gfx::Window& window, gfx::TextureCache& textureCache)
{
    spriteSheet_ = std::make_unique<sprite::SpriteSheet>(
        window.getRenderer(), textureCache, "assets/textures/SpriteSheet.png", sprite::SpriteSheetConfig{
            {"grid",   std::make_shared<sprite::SpriteClip>(0, 0, 360, 360)},
            {"x",      std::make_shared<sprite::SpriteClip>(360, 0, 120, 120)},
            {"o",      std::make_shared<sprite::SpriteClip>(360, 120, 120, 120)},
            {"button", std::make_shared<sprite::SpriteClip>(360, 245, 178, 65)}
        }
    );
}

void MainMenuScene::createTitleText(const gfx::Window& window)
{
    const std::string titleFontPath = "assets/fonts/PermanentMarker-Regular.ttf";
    const int titleFontSize = 44;
    const auto titleFont = std::make_shared<ui::Font>(titleFontPath, titleFontSize);

    const std::string titleTextDescription = "Tic-tac-toe";
    const ui::Color titleTextColor = {0x00, 0x00, 0x00};
    auto titleText = std::make_shared<ui::Text>(
        titleTextDescription, titleFont, titleTextColor, 0, 0, window.getRenderer()
    );
    titleText->x = window.getCenterPoint().x - titleText->getCenterPoint().x;

    const int titleTextPadding = 40;
    titleText->y = titleTextPadding;

    addChild(titleText);
}

void MainMenuScene::createSubtitleText(const gfx::Window& window)
{
    const std::string subtitleFontPath = "assets/fonts/PermanentMarker-Regular.ttf";
    const int subtitleFontSize = 24;
    const auto subtitleFont = std::make_shared<ui::Font>(subtitleFontPath, subtitleFontSize);

    const std::string subtitleTextDescription = "Game by @maunovaha";
    const ui::Color subtitleTextColor = {0x00, 0x00, 0x00};
    auto subtitleText = std::make_shared<ui::Text>(
        subtitleTextDescription, subtitleFont, subtitleTextColor, 0, 0, window.getRenderer()
    );
    subtitleText->x = window.getCenterPoint().x - subtitleText->getCenterPoint().x;

    const int titleTextPadding = 100;
    subtitleText->y = titleTextPadding;

    addChild(subtitleText);
}

void MainMenuScene::createStartButton(const gfx::Window& window)
{
    const std::string startButtonFontPath = "assets/fonts/LilitaOne-Regular.ttf";
    const int startButtonFontSize = 24;
    const auto startButtonFont = std::make_shared<ui::Font>(startButtonFontPath, startButtonFontSize);

    const std::string startButtonText = "LET'S PLAY";
    const ui::Color startButtonTextColor = {0x00, 0x00, 0x00};
    const auto startButtonBg = spriteSheet_->getSprite("button");
    auto startButton = std::make_shared<ui::Button>(
        startButtonText, startButtonFont, startButtonTextColor, startButtonBg, 0, 0, window.getRenderer()
    );
    startButton->x = window.getCenterPoint().x - startButton->getCenterPoint().x;

    const int startButtonPadding = 40;
    startButton->y = window.getHeight() - startButton->getHeight() - startButtonPadding;

    addChild(startButton);
}

void MainMenuScene::onUpdate()
{
}

}