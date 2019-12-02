#ifndef GAME_MAIN_MENU_MAIN_MENU_SCENE_H
#define GAME_MAIN_MENU_MAIN_MENU_SCENE_H

#include "../../engine/Scene.h"

namespace game::main_menu {

class MainMenuScene: public engine::Scene {
public:
    void create() override;
    void update() override;
};

}

#endif
