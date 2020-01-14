#include "GameOverScene.h"
#include "../shared/Text.h"
#include "../shared/Button.h"
#include "../gameplay/GameplayScene.h"
#include "../../engine/world/Transform.h"
#include "../../engine/ui/Text.h"
#include "../../engine/ui/Button.h"
#include "../../engine/math/Point.h"
#include "../../engine/core/AppContext.h"

namespace game::gameover {

using namespace engine;

void GameOverScene::onCreate()
{
    createGameOverText(getGameResult(), "PermanentMarker-Regular.ttf", 36, 100);
    createPlayAgainButton("PLAY AGAIN", "LilitaOne-Regular.ttf", 24, 40, 40);
    createQuitButton("QUIT", "LilitaOne-Regular.ttf", 24, 40, 40);
}

void GameOverScene::createGameOverText(const std::string& text, 
                                       const std::string& font, 
                                       const int size, 
                                       const int yPosition,
                                       const ui::Color& color)
{
    std::unique_ptr<shared::Text> textObj = std::make_unique<shared::Text>(text, font, size, math::Point{0, 0}, color);
    const ui::Text& textComp = textObj->getComponent<ui::Text>();
    const math::Point textCenterPoint = textComp.getCenter();
    const math::Point windowCenterPoint = core::AppContext::getWindow().getCenter();
    const int xPosition = windowCenterPoint.x - textCenterPoint.x;

    world::Transform& textTransformComp = textObj->getComponent<world::Transform>();
    textTransformComp.localPosition = math::Point{xPosition, yPosition};

    addChild(std::move(textObj));
}

void GameOverScene::createPlayAgainButton(const std::string& text,
                                          const std::string& font, 
                                          const int size,
                                          const int paddingLeft,
                                          const int paddingBottom,
                                          const ui::Color& color)
{
    std::unique_ptr<shared::Button> buttonObj = std::make_unique<shared::Button>(text, font, size, math::Point{0, 0}, color);
    ui::Button& buttonComp = buttonObj->getComponent<ui::Button>();
    const math::Point buttonCenterPoint = buttonComp.getCenter();

    const math::Point windowCenterPoint = core::AppContext::getWindow().getCenter();
    const int xPosition = paddingLeft;
    const int yPosition = core::AppContext::getWindow().getHeight() - buttonComp.getHeight() - paddingBottom;

    world::Transform& buttonTransformComp = buttonObj->getComponent<world::Transform>();
    buttonTransformComp.localPosition = math::Point{xPosition, yPosition};
    buttonComp.registerOnClickListener([]() {
        core::AppContext::getDirector().play(std::make_unique<gameplay::GameplayScene>());
    });

    addChild(std::move(buttonObj));
}

void GameOverScene::createQuitButton(const std::string& text,
                                     const std::string& font,
                                     const int size,
                                     const int paddingRight,
                                     const int paddingBottom,
                                     const ui::Color& color)
{
    std::unique_ptr<shared::Button> buttonObj = std::make_unique<shared::Button>(text, font, size, math::Point{0, 0}, color);
    ui::Button& buttonComp = buttonObj->getComponent<ui::Button>();
    const math::Point buttonCenterPoint = buttonComp.getCenter();

    const math::Point windowCenterPoint = core::AppContext::getWindow().getCenter();
    const int xPosition = core::AppContext::getWindow().getWidth() - buttonComp.getWidth() - paddingRight;
    const int yPosition = core::AppContext::getWindow().getHeight() - buttonComp.getHeight() - paddingBottom;

    world::Transform& buttonTransformComp = buttonObj->getComponent<world::Transform>();
    buttonTransformComp.localPosition = math::Point{xPosition, yPosition};
    buttonComp.registerOnClickListener([]() {
        core::AppContext::quit();
    });

    addChild(std::move(buttonObj));
}

std::string GameOverScene::getGameResult() const
{
    if (winner_) {
        return winner_->getName() + " wins!";
    }
    else {
        return "It was a draw!";
    }
}

}