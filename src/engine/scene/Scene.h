#pragma once

#include "GameObject.h"
#include <vector>
#include <memory>

namespace engine::scene {

class Scene {
public:
    virtual ~Scene() = default;
    virtual void onCreate() = 0;
    void update();
    void render() const;
protected:
    void addChild(std::shared_ptr<GameObject> gameObject);
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects_;
};

}