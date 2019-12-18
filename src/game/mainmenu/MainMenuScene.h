#pragma once

#include "../../engine/scene/Scene.h"
#include "../../engine/sprite/SpriteSheet.h"

namespace game::mainmenu {

class MainMenuScene: public engine::scene::Scene {
public:
    void onCreate() override;
private:
    void createSpriteSheet();
    void createTitleText();
    void createSubtitleText();
    void createStartButton();

    std::unique_ptr<engine::sprite::SpriteSheet> spriteSheet_;
};

}
