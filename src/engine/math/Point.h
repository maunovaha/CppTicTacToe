#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace engine::math {

class Point {
public:
    constexpr Point(const int x, const int y) : x{x}, y{y} {}

    constexpr operator SDL_Point() const
    {
        return {x, y};
    }

    constexpr Point operator +(const Point& other) const
    {
        return {x + other.x, y + other.y};
    }

    constexpr Point& operator +=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;

        return *this;
    }

    int x = 0;
    int y = 0;
};

}