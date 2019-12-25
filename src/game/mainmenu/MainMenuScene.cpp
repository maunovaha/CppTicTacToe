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
    createText("Tic-tac-toe", "PermanentMarker-Regular.ttf", 44, 40);
    createText("Game by @maunovaha", "PermanentMarker-Regular.ttf", 24, 100);
}

void MainMenuScene::createText(const std::string& text, 
                               const std::string& font, 
                               const int size, 
                               const int yPosition,
                               const ui::Color& color)
{
    std::unique_ptr<Text> textObj = std::make_unique<Text>(text, font, size, math::Point{0, 0}, color);
    const ui::Text& textComp = textObj->getComponent<ui::Text>();
    const math::Point textCenterPoint = textComp.getCenter();
    const math::Point windowCenterPoint = core::AppContext::getWindow().getCenter();
    const int xPosition = windowCenterPoint.x - textCenterPoint.x;

    world::Transform& textTransformComp = textObj->getComponent<world::Transform>();
    textTransformComp.localPosition = math::Point{xPosition, yPosition};

    addChild(std::move(textObj));
}

}