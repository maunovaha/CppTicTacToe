#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif
#include <string>
#include <memory>

namespace engine::gfx {

class Surface {
public:
    Surface(const std::string& imagePath);
    Surface(SDL_Surface* surface);
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

    using UniqueSurface = std::unique_ptr<SDL_Surface, DestroySurface>;

    UniqueSurface surface_;

    static constexpr SDL_Color CYAN = {0x00, 0xFF, 0xFF, 0xFF};
    static constexpr SDL_Color COLOR_KEY = CYAN;
};

}