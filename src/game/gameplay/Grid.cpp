#include "Grid.h"
#include "GridSlot.h"
#include "Chip.h"
#include "../../engine/ui/Image.h"
#include <memory>
#include <cassert>

namespace game::gameplay {

using namespace engine;

Grid::Grid(const math::Point& position, const int size) : scene::GameObject{position}
{
    static constexpr auto SPRITE_SHEET = "assets/textures/SpriteSheet.png";

    auto backgroundImageClip = std::make_unique<math::Rect>(0, 0, 360, 360);
    auto backgroundImage = std::make_unique<ui::Image>(SPRITE_SHEET, std::move(backgroundImageClip));
    addComponent(std::move(backgroundImage));

    static constexpr int GRID_SLOT_SIZE = 120; // Move to GridSlot (?)
    const int gridSlotCount = size * size;
 
    for (int i = 0; i < gridSlotCount; ++i) {
        const int gridSlotX = (i % size) * GRID_SLOT_SIZE;
        const int gridSlotY = (i / size) * GRID_SLOT_SIZE;
        const math::Point gridSlotPosition = {gridSlotX, gridSlotY};
        addChild(std::make_unique<GridSlot>(gridSlotPosition));
    }
}

int Grid::getGridSlotCount() const
{
    return getChildCount();
}

bool Grid::isFull() const
{
    const int gridSlotCount = getGridSlotCount();
    int freeGridSlotCount = gridSlotCount;

    for (int gridSlotIndex = 0; gridSlotIndex < gridSlotCount; ++gridSlotIndex) {
        GridSlot* gridSlot = static_cast<GridSlot*>(getChild(gridSlotIndex));

        if (!gridSlot->isFree()) {
            --freeGridSlotCount;
        }
    }

    return freeGridSlotCount == 0;
}

// Returns binary representation of this grid "state" in which value of "1" means that
// grid slot is taken and "0" means it is still free.
//
// E.g. when the grid has the following state and player chip type is "X"
//     X,     X,     X
// empty,     O,     O
// empty, empty, empty
//
//                                    X XX O O
//                                    | || | |
// This method will return: 0b0000'0001'1100'0000
//
// Hence, ofc. because the grid has only 9 slots, 7 bits from the left will be unused even when
// the grid is completelty full.
uint16_t Grid::toBinary(const ChipType playerChipType) const
{
    assert(getGridSlotCount() == 9); // This method is working only with 3x3 grid atm.

    uint16_t binaryGrid = 0b0;

    const int gridSlotCount = getGridSlotCount();

    for (int gridSlotIndex = 0; gridSlotIndex < gridSlotCount; ++gridSlotIndex) {
        GridSlot* gridSlot = static_cast<GridSlot*>(getChild(gridSlotIndex));
        Chip* placedChip = gridSlot->getChip();

        if (placedChip && placedChip->getChipType() == playerChipType) {
            // Shifts number "1" to left to proper position, because we want to read current
            // state of the grid in binary from left to right.
            binaryGrid += (1 << ((gridSlotCount - 1) - gridSlotIndex));
        }
    }

    // Uncomment this if you want to debug things..
    // 
    // std::string binaryStr = "0b";
    // const int bitCount = 16; // uint16_t
       
    // for (int i = 0; i < bitCount; ++i) {
    //     const int bs = (bitCount - 1) - i;
    //     binaryStr += std::to_string(static_cast<int>((binaryGrid & (1 << bs)) >> bs));
    // }
       
    // std::cout << "The current grid state in binary: " << binaryStr << std::endl;

    return binaryGrid;
}

}
