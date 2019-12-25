#include "MainMenuScene.h"
#include "Text.h"
#include "../../engine/world/Transform.h"
#include "../../engine/ui/Text.h"
#include "../../engine/math/Point.h"
#include "../../engine/core/AppContext.h"
#include <memory>

namespace game::mainmenu {

using namespace engine;

void MainMenuScene::onCreate()
{
    createTitleText("Tic-tac-toe", "PermanentMarker-Regular.ttf", 44, ui::Color::black());
}

void MainMenuScene::createTitleText(const std::string& text, 
                                    const std::string& font, 
                                    const int size, 
                                    const ui::Color& color)
{
    std::unique_ptr<Text> titleText = std::make_unique<Text>(text, font, size, math::Point{50, 50}, color);

    const ui::Text& titleTextUI = titleText->getComponent<ui::Text>();
    const math::Point titleTextCenterPoint = titleTextUI.getCenter();
    const math::Point windowCenterPoint = core::AppContext::getWindow().getCenter();
    const int titleTextX = windowCenterPoint.x - titleTextCenterPoint.x;

    const int titleTextPaddingTop = 40;
    const int titleTextY = titleTextPaddingTop;

    world::Transform& titleTextTransform = titleText->getComponent<world::Transform>();
    titleTextTransform.localPosition = math::Point{titleTextX, titleTextY};

    addChild(std::move(titleText));
}

}