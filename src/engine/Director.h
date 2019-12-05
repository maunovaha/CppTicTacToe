#pragma once

#include "Scene.h"
#include "Window.h"
#include <memory>

namespace engine {

class Director {
public:
    void play(std::unique_ptr<Scene> scene, const Window& window);
    void update();
    void render(const Window& window) const;
    bool isPlaying() const;

    // TODO: Access to window/renderer/app settings(?)

private:
    std::unique_ptr<Scene> currentScene_;
};

}