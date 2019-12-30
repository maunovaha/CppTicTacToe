#pragma once

#include "../gameplay/ChipType.h"
#include <string>

namespace game::shared {

class Player {
public:
    Player(const gameplay::ChipType chipType) : chipType_{chipType} {}
    gameplay::ChipType getChipType() const;
    std::string getName() const;
private:
    gameplay::ChipType chipType_;
};

}
