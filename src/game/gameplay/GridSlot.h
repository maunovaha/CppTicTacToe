#pragma once

#include "Chip.h"
#include "ChipType.h"
#include "../../engine/scene/GameObject.h"
#include "../../engine/math/Point.h"

namespace game::gameplay {

class GridSlot : public engine::scene::GameObject {
public:
    GridSlot(const engine::math::Point& position);
    Chip* getChip() const;
    bool isFree() const;
private:
    void onClick();
    void placeChip(const ChipType chipType);
};

}