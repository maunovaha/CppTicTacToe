#include "Grid.h"
#include "GridSlot.h"
#include "../../engine/ui/Image.h"
#include <memory>

namespace game::gameplay {

using namespace engine;

Grid::Grid(const math::Point& position, const int size) : scene::GameObject{position}
{
    static constexpr auto SPRITE_SHEET = "assets/textures/SpriteSheet.png";

    auto backgroundImageClip = std::make_unique<math::Rect>(0, 0, 360, 360);
    auto backgroundImage = std::make_unique<ui::Image>(SPRITE_SHEET, std::move(backgroundImageClip));

    addComponent(std::move(backgroundImage));

    static constexpr int GRID_SLOT_SIZE = 120; // Move to GridSlot (?)

    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            const int gridSlotX = row * GRID_SLOT_SIZE;
            const int gridSlotY = column * GRID_SLOT_SIZE;
            const math::Point gridSlotPosition{gridSlotX, gridSlotY};

            auto gridSlot = std::make_unique<GridSlot>(gridSlotPosition);
            addChild(std::move(gridSlot));
        }
    }
}

}
