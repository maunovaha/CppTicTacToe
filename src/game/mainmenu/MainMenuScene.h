#pragma once

#include "../../engine/scene/Scene.h"
#include "../../engine/sprite/SpriteSheet.h"
#include <memory>

namespace game::mainmenu {

class MainMenuScene: public engine::scene::Scene {
public:
    void onCreate(const engine::gfx::Window& window, engine::gfx::TextureCache& textureCache) override;
    void onUpdate() override;
private:
    void loadSpriteSheet(const engine::gfx::Window& window, engine::gfx::TextureCache& textureCache);
    void createTitleText(const engine::gfx::Window& window);
    void createSubtitleText(const engine::gfx::Window& window);
    void createStartButton(const engine::gfx::Window& window);

    std::unique_ptr<engine::sprite::SpriteSheet> spriteSheet_;
};

}
