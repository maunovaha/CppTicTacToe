#pragma once

#include "../math/Point.h"

namespace engine::scene {

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void onUpdate() {}
    virtual void onRender(const math::Point& parentPosition) const = 0;

    constexpr void setPosition(const int x, const int y)
    {
        this->x = x;
        this->y = y;
    }

    int x = 0;
    int y = 0;
protected:
    GameObject(const int x, const int y) : x{x}, y{y} {}
};

}