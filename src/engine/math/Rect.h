#pragma once

#include "Point.h"
#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace engine::math {

class Rect {
public:
    constexpr Rect(const int x, const int y, const int width, const int height)
        : x{x}, y{y}, width{width}, height{height} {}

    constexpr operator SDL_Rect() const
    {
        return {x, y, width, height};
    }

    constexpr bool contains(const math::Point& point) const
    {
        return point.x >= x && point.x <= (x + width) &&
               point.y >= y && point.y <= (y + height);
    }

    constexpr math::Point getCenter() const
    {
        return {width / 2, height / 2};
    }

    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
};

}