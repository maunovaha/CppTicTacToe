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
        : red{red}, green{green}, blue{blue}, alpha{alpha} {}

    constexpr operator SDL_Color() const
    {
        return {red, green, blue, alpha};
    }

    static inline Color black()
    {
        return {0x00, 0x00, 0x00};
    }

    Uint8 red   = 0x00;
    Uint8 green = 0x00;
    Uint8 blue  = 0x00;
    Uint8 alpha = 0xFF;
};

}
