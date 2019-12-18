#pragma once

#include "Grid.h"
#include "../../engine/scene/Scene.h"
#include "../../engine/sprite/SpriteSheet.h"

namespace game::gameplay {

class GameplayScene: public engine::scene::Scene {
public:
    void onCreate() override;
    void onUpdate() override;
private:
    void createSpriteSheet();
    void createGrid();

    std::unique_ptr<engine::sprite::SpriteSheet> spriteSheet_;
    std::shared_ptr<Grid> grid_;
};

}
