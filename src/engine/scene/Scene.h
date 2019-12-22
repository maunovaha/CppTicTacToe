#pragma once

#include "GameObject.h"
#include <memory>

namespace engine::scene {

class Scene {
public:
    virtual ~Scene() = default;
    virtual void onCreate() = 0;
    void update();
    void render() const;
protected:
    Scene(); // Scenes are created via inheritance (also, "onCreate() = 0;" guarantees that).
    void addChild(std::unique_ptr<GameObject> child);
private:
    std::unique_ptr<GameObject> root_;
};

}