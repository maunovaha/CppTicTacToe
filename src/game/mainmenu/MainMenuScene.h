#pragma once

#include "../../engine/scene/Scene.h"

namespace game::mainmenu {

class MainMenuScene: public engine::scene::Scene {
public:
    void onCreate(const engine::gfx::Window& window, engine::gfx::TextureCache& textureCache) override;
    void onUpdate() override;
};

}
