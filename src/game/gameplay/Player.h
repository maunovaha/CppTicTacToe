#pragma once

#include "ChipType.h"
#include <string>

namespace game::gameplay {

class Player {
public:
    Player(const ChipType chipType) : chipType_{chipType} {}
    ChipType getChipType() const;
    std::string getName() const;
private:
    ChipType chipType_;
};

}
