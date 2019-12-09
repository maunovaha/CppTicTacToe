#pragma once

#include "../sdl2wrap/Renderer.h"

namespace engine {

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void render(const sdl2wrap::Renderer& renderer) const = 0;

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