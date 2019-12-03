#ifndef GAME_MAINMENU_MAIN_MENU_SCENE_H
#define GAME_MAINMENU_MAIN_MENU_SCENE_H

#include "../../engine/Scene.h"

namespace game::mainmenu {

class MainMenuScene: public engine::Scene {
public:
    void create() override;
    void update() override;
};

}

#endif
