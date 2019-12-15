#pragma once

#include "../../engine/scene/Scene.h"

namespace game::mainmenu {

class MainMenuScene: public engine::scene::Scene {
public:
    void create(const engine::gfx::Window& window, engine::gfx::TextureCache& textureCache) override;
    void update() override;
};

}
