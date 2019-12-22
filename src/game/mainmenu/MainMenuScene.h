#pragma once

#include "../../engine/scene/Scene.h"
#include "../../engine/ui/Color.h"
#include <string>

namespace game::mainmenu {

class MainMenuScene: public engine::scene::Scene {
public:
    void onCreate() override;
private:
    void createTitleText(const std::string& text,
                         const std::string& font,
                         const int size,
                         const engine::ui::Color& color);
};

}
