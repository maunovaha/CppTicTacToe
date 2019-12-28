#pragma once

#include "Scene.h"
#include <memory>

namespace engine::scene {

class Director {
public:
    void start(std::unique_ptr<Scene> startingScene);
    void play(std::unique_ptr<Scene> scene);
    void update();
    void render() const;
    bool isLoading() const;
private:
    bool isStarted() const;
    
    std::unique_ptr<Scene> currentScene_;
    std::unique_ptr<Scene> nextScene_;
};

}