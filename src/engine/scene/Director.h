#pragma once

#include "Scene.h"
#include "../gfx/Window.h"
#include "../gfx/TextureCache.h"
#include <memory>

namespace engine::scene {

class Director {
public:
    void play(std::unique_ptr<Scene> scene, const gfx::Window& window, gfx::TextureCache& textureCache);
    void update();
    void render(const gfx::Window& window) const;
    bool isPlaying() const;
private:
    std::unique_ptr<Scene> currentScene_;
};

}