#pragma once

#include "../world/Transform.h"
#include "../math/Point.h"
// #include "../math/Rect.h"

namespace engine::ui {

class RectTransform : public world::Transform {
public:
    RectTransform(const math::Point& localPosition) : world::Transform{localPosition} {}

    math::Point getSize() const
    {
        return {width, height};
    }

    math::Point getCenter() const
    {
        const math::Point size = getSize();

        return {size.x / 2, size.y / 2};
    }

    int width = 0;
    int height = 0;
};

}