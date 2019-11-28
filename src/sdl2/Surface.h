#ifndef SDL2_SURFACE_H
#define SDL2_SURFACE_H

#include <SDL2/SDL.h>
#include <string>
#include <memory>

namespace sdl2 {

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

#endif