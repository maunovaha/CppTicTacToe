#pragma once

#include "../../engine/Scene.h"

namespace game::mainmenu {

class MainMenuScene: public engine::Scene {
public:
    void create() override;
    void update() override;
};

}
