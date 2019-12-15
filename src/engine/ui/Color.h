#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace engine::ui {

class Color {
public:
    constexpr Color(const uint8_t red, 
                    const uint8_t green, 
                    const uint8_t blue, 
                    const uint8_t alpha = 0xFF)
        : color_{red, green, blue, alpha} {}

    constexpr operator SDL_Color() const
    {
        return color_;
    }
private:
    SDL_Color color_;
};

}
