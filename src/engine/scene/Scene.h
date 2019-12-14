#pragma once

#include "GameObject.h"
#include "../Window.h"
#include "../TextureCache.h"
#include <vector>
#include <memory>

namespace engine::scene {

class Scene {
public:
    virtual ~Scene() = default;
    virtual void create(const Window& window, TextureCache& textureCache) = 0;
    virtual void update() = 0;
    void render(const Window& window) const;
protected:
    void addChild(std::shared_ptr<GameObject> gameObject);
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects_;
};

}