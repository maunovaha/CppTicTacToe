#include "Grid.h"
#include "../../engine/ui/Image.h"
#include <memory>

namespace game::gameplay {

using namespace engine;

Grid::Grid(const math::Point& position) : scene::GameObject{position}
{
    const std::string spriteSheetPath = "assets/textures/SpriteSheet.png";
    std::unique_ptr<math::Rect> backgroundClip = std::make_unique<math::Rect>(0, 0, 360, 360);
    addComponent(std::make_unique<ui::Image>(spriteSheetPath, std::move(backgroundClip)));
}

}
