#ifndef ENGINE_SCENE_H
#define ENGINE_SCENE_H

#include "GameObject.h"
#include <vector>
#include <memory>

namespace engine {

class Scene {
public:
    virtual ~Scene() = default;
    virtual void update() {}
    void draw() const;
protected:
    void add_child(std::shared_ptr<GameObject> game_object);
private:
    std::vector<std::shared_ptr<GameObject>> game_objects_;
};

}

#endif