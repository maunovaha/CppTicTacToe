#include "MainMenuScene.h"
#include "Text.h"
#include "../../engine/math/Point.h"
#include "../../engine/ui/RectTransform.h"
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
    auto titleText = std::make_unique<Text>(text, font, size, math::Point{0, 0}, color);

    ui::RectTransform& tilteTextTransform = titleText->getComponent<ui::RectTransform>();

    const math::Point windowCenterPoint = core::AppContext::getWindow().getCenter();
    const math::Point titleTextCenterPoint = tilteTextTransform.getCenter();
    const int titleTextX = windowCenterPoint.x - titleTextCenterPoint.x;

    const int titleTextPaddingTop = 40;
    const int titleTextY = titleTextPaddingTop;

    tilteTextTransform.localPosition = math::Point{titleTextX, titleTextY};

    addChild(std::move(titleText));
}

}