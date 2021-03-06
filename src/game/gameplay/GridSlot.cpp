#include "GridSlot.h"
#include "GameLogic.h"
#include "../../engine/ui/Button.h"
#include <memory>
#include <cassert>

namespace game::gameplay {

using namespace engine;

GridSlot::GridSlot(const math::Point& position) : scene::GameObject{position}
{
    static constexpr auto SPRITE_SHEET = "assets/textures/SpriteSheet.png";

    auto buttonBackgroundImageClip = std::make_unique<math::Rect>(480, 0, 120, 120);
    auto button = std::make_unique<ui::Button>(SPRITE_SHEET, std::move(buttonBackgroundImageClip));

    button->registerOnClickListener([&]() {
        onClick();
    });

    addComponent(std::move(button));
}

Chip* GridSlot::getChip() const
{
    static constexpr unsigned int CHIP_INDEX = 0;
    return static_cast<Chip*>(getChild(CHIP_INDEX));
}

bool GridSlot::isFree() const
{
    return static_cast<bool>(!getChip());
}

void GridSlot::onClick()
{
    if (isFree()) {
        GameLogic* gameLogic = findWithTag<GameLogic>("GameLogic");
        assert(gameLogic); // Programmer error, someone forgot to tag "GameLogic"

        placeChip(gameLogic->getCurrentPlayer().getChipType());

        // This class should not be responsible of commanding "GameLogic", but in this simple
        // game it doesnt really matter.
        gameLogic->checkGameStatus(reinterpret_cast<Grid*>(getParent()));
    }
}

void GridSlot::placeChip(const ChipType chipType)
{
    assert(isFree());
    addChild(std::make_unique<Chip>(chipType));
}

}
