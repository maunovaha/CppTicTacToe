#pragma once

#include "../core/Component.h"
#include "../math/Point.h"

namespace engine::world {

class Transform : public core::Component {
public:
    Transform(const math::Point& position) : core::Component{"Transform"}, position{position} {}

    math::Point position;
};

}