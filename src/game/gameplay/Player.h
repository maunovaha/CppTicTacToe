#pragma once

#include "ChipType.h"

namespace game::gameplay {

class Player {
public:
    Player(const ChipType chipType) : chipType_{chipType} {}
    ChipType getChipType() const;
private:
    ChipType chipType_;
};

}
