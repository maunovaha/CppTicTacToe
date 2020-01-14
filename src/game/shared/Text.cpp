#include "Text.h"
#include "../../engine/core/Component.h"
#include "../../engine/ui/Font.h"
#include "../../engine/ui/Text.h"
#include <memory>

namespace game::shared {

using namespace engine;

Text::Text(const std::string& text,
           const std::string& fontName,
           const int fontSize,
           const math::Point& position,
           const ui::Color& color) 
    : scene::GameObject{position}
{
    const std::string fontPath = FONTS_BASE_PATH + fontName;
    const ui::Font font{fontPath, fontSize};

    addComponent(std::make_unique<ui::Text>(text, font, color));
}

}
