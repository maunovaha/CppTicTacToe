#pragma once

namespace engine {

class GameObject {
public:
    GameObject() = default;
    GameObject(const int x, const int y) : x_{x}, y_{y} {}
    virtual ~GameObject() = default;
    virtual void update() = 0;
    virtual void render() const = 0;
protected:
    int x_ = 0;
    int y_ = 0;
};

}
