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
    Surface(const std::string& image_path);
    int width() const;
    int height() const;
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
};

}
