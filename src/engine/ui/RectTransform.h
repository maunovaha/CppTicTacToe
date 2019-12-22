#pragma once

#include "../world/Transform.h"
#include "../math/Point.h"
#include "../math/Rect.h"

namespace engine::ui {

class RectTransform : public world::Transform {
public:
    RectTransform(const math::Point& localPosition)
        : world::Transform{localPosition} {}

    math::Rect rect{0,0,0,0}; // TODO: Init based on image? or take param?
};

}