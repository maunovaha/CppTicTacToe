#include "MainMenuScene.h"
#include "../../engine/ui/Text.h"
#include "../../engine/ui/Button.h"

namespace game::mainmenu {

using namespace engine::core;
using namespace engine::sprite;
using namespace engine::ui;

void MainMenuScene::onCreate()
{
    loadSpriteSheet();
    createTitleText();
    createSubtitleText();
    createStartButton();
}

void MainMenuScene::loadSpriteSheet()
{
    spriteSheet_ = std::make_unique<SpriteSheet>(
        "assets/textures/SpriteSheet.png", SpriteSheet::Config{
            {"grid",   std::make_shared<SpriteSheet::SpriteClip>(0, 0, 360, 360)},
            {"x",      std::make_shared<SpriteSheet::SpriteClip>(360, 0, 120, 120)},
            {"o",      std::make_shared<SpriteSheet::SpriteClip>(360, 120, 120, 120)},
            {"button", std::make_shared<SpriteSheet::SpriteClip>(360, 245, 178, 65)}
        }
    );
}

void MainMenuScene::createTitleText()
{
    const auto titleFont = std::make_shared<Font>("assets/fonts/PermanentMarker-Regular.ttf", 44);
    auto titleText = std::make_shared<Text>("Tic-Tac-Toe", titleFont, Color::black(), 0, 0);
    const int titleTextPaddingTop = 40;
    const int titleTextY = titleTextPaddingTop;
    const int titleTextX = AppContext::getWindow().getCenterPoint().x - titleText->getCenterPoint().x;
    titleText->setPosition(titleTextX, titleTextY);

    addChild(titleText);
}

void MainMenuScene::createSubtitleText()
{
    const auto subtitleFont = std::make_shared<Font>("assets/fonts/PermanentMarker-Regular.ttf", 24);
    auto subtitleText = std::make_shared<Text>("Game by @maunovaha", subtitleFont, Color::black(), 0, 0);
    const int subtitleTextPaddingTop = 100;
    const int subtitleTextY = subtitleTextPaddingTop;
    const int subtitleTextX = AppContext::getWindow().getCenterPoint().x - subtitleText->getCenterPoint().x;
    subtitleText->setPosition(subtitleTextX, subtitleTextY);

    addChild(subtitleText);
}

void MainMenuScene::createStartButton()
{
    const auto startButtonFont = std::make_shared<Font>("assets/fonts/LilitaOne-Regular.ttf", 24);
    auto startButton = std::make_shared<Button>(
        "LET'S PLAY", startButtonFont, Color::black(), spriteSheet_->getSprite("button"), 0, 0
    );
    const int startButtonPaddingBottom = 40;
    const int startButtonY = AppContext::getWindow().getHeight() - startButton->getHeight() - startButtonPaddingBottom;
    const int startButtonX = AppContext::getWindow().getCenterPoint().x - startButton->getCenterPoint().x;
    startButton->setPosition(startButtonX, startButtonY);
    startButton->registerOnClickListener([]() {
        // TODO: Change scene
    });

    addChild(startButton);
}

}