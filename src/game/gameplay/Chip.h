#pragma once

#include "ChipType.h"
#include "../../engine/scene/GameObject.h"
#include "../../engine/math/Rect.h"
#include <memory>

namespace game::gameplay {

class Chip : public engine::scene::GameObject {
public:
    Chip(ChipType chipType);
    ChipType getChipType() const;
private:
    std::unique_ptr<engine::math::Rect> getChipImageClip();

    ChipType chipType_;
};

}