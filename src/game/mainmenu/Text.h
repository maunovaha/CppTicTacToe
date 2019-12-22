#pragma once

#include "../../engine/scene/GameObject.h"
#include "../../engine/math/Point.h"
#include "../../engine/ui/Color.h"

namespace game::mainmenu {

class Text: public engine::scene::GameObject {
public:
    Text(const std::string& text,
         const std::string& fontName,
         const int fontSize,
         const engine::math::Point& position,
         const engine::ui::Color& color);
private:
    static constexpr auto FONTS_BASE_PATH = "assets/fonts/";
};

}