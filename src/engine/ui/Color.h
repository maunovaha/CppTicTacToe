#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace engine::ui {

class Color {
public:
    constexpr Color(const Uint8 red,
                    const Uint8 green,
                    const Uint8 blue,
                    const Uint8 alpha = 0xFF)
        : color_{red, green, blue, alpha} {}

    constexpr operator SDL_Color() const
    {
        return color_;
    }

    constexpr Uint8 getRed() const
    {
        return color_.r;
    }

    constexpr Uint8 getGreen() const
    {
        return color_.g;
    }

    constexpr Uint8 getBlue() const
    {
        return color_.b;
    }

    constexpr Uint8 getAlpha() const
    {
        return color_.a;
    }
private:
    SDL_Color color_;
};

}
