#pragma once

#include "Scene.h"
#include <memory>

namespace engine {

class Director {
public:
    void play(std::unique_ptr<Scene> scene);
    void update();
    void render() const;
    bool isPlaying() const;
private:
    std::unique_ptr<Scene> currentScene_;
};

}