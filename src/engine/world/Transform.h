#pragma once

#include "../core/Component.h"
#include "../math/Point.h"

namespace engine::world {

class Transform : public core::Component {
public:
    Transform(const math::Point& position) : position{position} {}

    math::Point position;
};

}