#pragma once

#include "GameObject.h"
#include "../gfx/Window.h"
#include "../gfx/TextureCache.h"
#include <vector>
#include <memory>

namespace engine::scene {

class Scene {
public:
    virtual ~Scene() = default;
    virtual void onCreate() = 0;
    virtual void onUpdate() = 0;
    void preUpdate();
    void render(const gfx::Window& window) const;
protected:
    void addChild(std::shared_ptr<GameObject> gameObject);
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects_;
};

}