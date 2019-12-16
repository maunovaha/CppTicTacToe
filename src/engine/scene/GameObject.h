#pragma once

#include "../gfx/Renderer.h"

namespace engine::scene {

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void onRender(const gfx::Renderer& renderer) const = 0;
    virtual void onUpdate() {}

    constexpr void setPosition(const int x, const int y)
    {
        x_ = x;
        y_ = y;
    }
protected:
    GameObject(const int x, const int y) : x_{x}, y_{y} {}

    int x_ = 0;
    int y_ = 0;
};

}