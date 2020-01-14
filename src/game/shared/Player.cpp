#include "Player.h"
#include <stdexcept>

namespace game::shared {

using namespace gameplay;

ChipType Player::getChipType() const
{
    return chipType_;
}

std::string Player::getName() const
{
    switch (chipType_) {
    case ChipType::X:
        return "Player X";
    case ChipType::O:
        return "Player O";
    default:
        throw std::invalid_argument("Could not get player name!");
    }
}

}
