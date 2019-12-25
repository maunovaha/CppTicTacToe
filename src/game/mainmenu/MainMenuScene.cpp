#include "MainMenuScene.h"
#include "Text.h"
#include "Button.h"
#include "../../engine/world/Transform.h"
#include "../../engine/ui/Text.h"
#include "../../engine/ui/Button.h"
#include "../../engine/math/Point.h"
#include "../../engine/core/AppContext.h"
#include <memory>

namespace game::mainmenu {

using namespace engine;

void MainMenuScene::onCreate()
{
    createText("Tic-tac-toe", "PermanentMarker-Regular.ttf", 44, 40);
    createText("Game by @maunovaha", "PermanentMarker-Regular.ttf", 24, 100);
    createStartButton("LET'S PLAY", "LilitaOne-Regular.ttf", 24, 40);
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

void MainMenuScene::createStartButton(const std::string& text, 
                                      const std::string& font, 
                                      const int size,
                                      const int paddingBottom,
                                      const ui::Color& color)
{
    std::unique_ptr<Button> buttonObj = std::make_unique<Button>(text, font, size, math::Point{0, 0}, color);
    ui::Button& buttonComp = buttonObj->getComponent<ui::Button>();
    const math::Point buttonCenterPoint = buttonComp.getCenter();

    const math::Point windowCenterPoint = core::AppContext::getWindow().getCenter();
    const int xPosition = windowCenterPoint.x - buttonCenterPoint.x;
    const int yPosition = core::AppContext::getWindow().getHeight() - buttonComp.getHeight() - paddingBottom;

    world::Transform& buttonTransformComp = buttonObj->getComponent<world::Transform>();
    buttonTransformComp.localPosition = math::Point{xPosition, yPosition};
    buttonComp.registerOnClickListener([]() {
        // AppContext::getDirector().play(std::make_unique<gameplay::GameplayScene>());
    });

    addChild(std::move(buttonObj));
}

}