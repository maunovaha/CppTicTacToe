#pragma once

#include "Scene.h"
#include "../Window.h"
#include "../TextureCache.h"
#include <memory>

namespace engine::scene {

class Director {
public:
    void play(std::unique_ptr<Scene> scene, const Window& window, TextureCache& textureCache);
    void update();
    void render(const Window& window) const;
    bool isPlaying() const;
private:
    std::unique_ptr<Scene> currentScene_;
};

}