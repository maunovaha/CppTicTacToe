#include "Grid.h"

namespace game::gameplay {

using namespace engine::sprite;
using namespace engine::scene;
using namespace engine::math;

Grid::Grid(std::shared_ptr<Sprite> background, const int x, const int y) 
    : GameObject{x, y}
    , background_{std::move(background)}
{
}

void Grid::onUpdate()
{
}

void Grid::onRender() const
{
    background_->onRender();
}

}