#pragma once

#include "../../engine/scene/GameObject.h"
#include "../../engine/math/Point.h"

namespace game::gameplay {

class Grid : public engine::scene::GameObject {
public:
    Grid(const engine::math::Point& position);
};

}