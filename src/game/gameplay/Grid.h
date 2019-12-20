#pragma once

#include "GridSlot.h"
#include "../../engine/sprite/Sprite.h"
#include <vector>
#include <memory>

namespace game::gameplay {

class Grid : public engine::scene::GameObject {
public:
    Grid(std::shared_ptr<engine::sprite::Sprite> background, const int x, const int y);
    void onUpdate() override;
    void onRender() const override;
private:
    using Grid2dRow = std::vector<GridSlot>;
    using Grid2d    = std::vector<Grid2dRow>;

    std::unique_ptr<Grid2d> grid_;
    std::shared_ptr<engine::sprite::Sprite> background_;
};

}