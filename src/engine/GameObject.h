#ifndef ENGINE_GAME_OBJECT_H
#define ENGINE_GAME_OBJECT_H

#include <vector>
#include <memory>

namespace engine {

class GameObject {
public:
    GameObject() = default;
    GameObject(const int x, const int y) : x_{x}, y_{y} {}
    virtual ~GameObject() = default;
    virtual void update() {}
    virtual void draw() const {}
protected:
    int x_ = 0;
    int y_ = 0;
};

}

#endif