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

    int x = 0;
    int y = 0;
};

}