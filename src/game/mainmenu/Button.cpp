#include "Button.h"
#include "Text.h"
#include "../../engine/math/Rect.h"
#include "../../engine/ui/Font.h"
#include "../../engine/ui/Button.h"
#include "../../engine/world/Transform.h"
#include <memory>

namespace game::mainmenu {

using namespace engine;

Button::Button(const std::string& text,
               const std::string& fontName,
               const int fontSize,
               const math::Point& position,
               const ui::Color& color) 
    : scene::GameObject{position}
{
    const std::string spriteSheetPath = "assets/textures/SpriteSheet.png";
    std::unique_ptr<math::Rect> buttonClip = std::make_unique<math::Rect>(360, 245, 178, 65);
    addComponent(std::make_unique<ui::Button>(spriteSheetPath, std::move(buttonClip)));
  
    std::unique_ptr<Text> textObj = std::make_unique<Text>(
        text, fontName, fontSize, math::Point{0, 0}, color
    );
    const ui::Text& textComp = textObj->getComponent<ui::Text>();
    const math::Point textCenterPoint = textComp.getCenter();

    const ui::Button& buttonComp = this->getComponent<ui::Button>();
    const math::Point buttonCenterPoint = buttonComp.getCenter();

    // The magic number is used atm. because the button graphic contains a shadow underneath.
    const int buttonShadowHeight = 2;
    const int textY = buttonCenterPoint.y - textCenterPoint.y - buttonShadowHeight;
    const int textX = buttonCenterPoint.x - textCenterPoint.x;

    world::Transform& textTransformComp = textObj->getComponent<world::Transform>();
    textTransformComp.localPosition = math::Point{textX, textY};

    addChild(std::move(textObj));
}

}
