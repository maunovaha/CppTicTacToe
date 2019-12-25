#pragma once

#include "../../engine/scene/Scene.h"
#include "../../engine/ui/Color.h"
#include <string>

namespace game::mainmenu {

class MainMenuScene: public engine::scene::Scene {
public:
    void onCreate() override;
private:
    void createText(const std::string& text,
                    const std::string& font,
                    const int size,
                    const int yPosition,
                    const engine::ui::Color& color = engine::ui::Color::black());
};

}
