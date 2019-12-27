#pragma once

#include "../../engine/scene/GameObject.h"
#include "../../engine/math/Point.h"
#include "../../engine/ui/Color.h"

namespace game::mainmenu {

class Button : public engine::scene::GameObject {
public:
    Button(const std::string& text,
           const std::string& fontName,
           const int fontSize,
           const engine::math::Point& position,
           const engine::ui::Color& color);
};

}