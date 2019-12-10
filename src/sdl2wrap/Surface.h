#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif
#include <string>
#include <memory>

namespace sdl2wrap {

class Surface {
public:
    Surface(const std::string& imagePath);
    int getWidth() const;
    int getHeight() const;
    SDL_Surface* get() const;
private:
    struct DestroySurface {
        void operator()(SDL_Surface* surface) const
        {
            SDL_FreeSurface(surface);
        }
    };

    using UniqueSurfacePtr = std::unique_ptr<SDL_Surface, DestroySurface>;

    UniqueSurfacePtr surface_;

    static constexpr SDL_Color CYAN = {0x00, 0xFF, 0xFF, 0xFF};
    static constexpr SDL_Color COLOR_KEY = CYAN;
};

}