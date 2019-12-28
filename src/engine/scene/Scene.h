#pragma once

#include "GameObject.h"
#include <memory>

namespace engine::scene {

class Scene {
public:
    virtual ~Scene() = default;
    virtual void onCreate() = 0;
    virtual void onExit() {}
    void update();
    void render() const;
protected:
    // Scenes are created via inheritance (also, "onCreate() = 0;" guarantees that).
    // In addition, every scene has a "root" game object by default; This makes calling 
    // render/update easier.
    Scene() : root_{std::make_unique<GameObject>()} {}
    void addChild(std::unique_ptr<GameObject> child);
    GameObject* getChild(const unsigned int index) const;
private:
    std::unique_ptr<GameObject> root_;
};

}