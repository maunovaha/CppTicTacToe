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
    void add_child(std::shared_ptr<GameObject> game_object);
private:
    std::vector<std::shared_ptr<GameObject>> game_objects_;
};

}
