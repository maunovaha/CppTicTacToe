#pragma once

#include "ChipType.h"
#include "../../engine/scene/GameObject.h"
#include "../../engine/math/Point.h"

namespace game::gameplay {

class Grid : public engine::scene::GameObject {
public:
    Grid(const engine::math::Point& position, const int size);
    bool isFull() const;
    uint16_t toBinary(const ChipType playerChipType) const;
    int getGridSlotCount() const;
};

}