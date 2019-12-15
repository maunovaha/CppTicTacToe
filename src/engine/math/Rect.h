#pragma once

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

    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
};

}