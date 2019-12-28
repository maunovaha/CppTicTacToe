#include "Chip.h"
#include "../../engine/ui/Image.h"
#include <stdexcept>

namespace game::gameplay {

using namespace engine;

Chip::Chip(const ChipType chipType)
{
    static constexpr auto SPRITE_SHEET = "assets/textures/SpriteSheet.png";

    auto chipImageClip = getChipImageClip(chipType);
    auto chipImage = std::make_unique<ui::Image>(SPRITE_SHEET, std::move(chipImageClip));
    
    addComponent(std::move(chipImage));
}

std::unique_ptr<math::Rect> Chip::getChipImageClip(const ChipType chipType)
{
    switch (chipType) {
    case ChipType::X:
        return std::make_unique<math::Rect>(360, 0, 120, 120);
    case ChipType::O:
        return std::make_unique<math::Rect>(360, 120, 120, 120);
    default:
        throw std::invalid_argument("The given chipType is not handled!");
    }
}

}
