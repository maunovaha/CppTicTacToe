#pragma once

#include "../../engine/Scene.h"

namespace game::mainmenu {

class MainMenuScene: public engine::Scene {
public:
    void create(const engine::Window& window) override;
    void update() override;
};

}
