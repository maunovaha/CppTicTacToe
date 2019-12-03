#pragma once

#include "GameObject.h"
#include <vector>
#include <memory>

namespace engine {

class Scene {
public:
    virtual ~Scene() = default;
    virtual void create() = 0;
    virtual void update() = 0;
    void render() const;
protected:
    void addChild(std::shared_ptr<GameObject> gameObject);
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects_;
};

}
