#pragma once

#include "../world/Transform.h"
#include "../math/Rect.h"
#include "../math/Point.h"

namespace engine::ui {

class RectTransform : public world::Transform {
public:
    RectTransform(const math::Point& position) : world::Transform{position}, rect{0, 0, 0, 0} {}

    math::Rect rect;
};

}