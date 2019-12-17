#pragma once

#include "../../engine/scene/Scene.h"
#include "../../engine/sprite/SpriteSheet.h"

namespace game::gameplay {

class GameplayScene: public engine::scene::Scene {
public:
    void onCreate() override;
    void onUpdate() override;
private:
    void loadSpriteSheet();

    std::unique_ptr<engine::sprite::SpriteSheet> spriteSheet_;
};

}
