#include "Surface.h"
#if defined(_WIN32)
    #include <SDL_image.h>
#else
    #include <SDL2/SDL_image.h>
#endif
#include <stdexcept>

namespace sdl2wrap {

Surface::Surface(const std::string& imagePath) : surface_{IMG_Load(imagePath.c_str())}
{
    if (!surface_) {
        throw std::runtime_error("Could not create surface, " + std::string{IMG_GetError()});
    }
}

int Surface::getWidth() const
{
    return surface_->w;
}

int Surface::getHeight() const
{
    return surface_->h;
}

SDL_Surface* Surface::get() const
{
    return surface_.get();
}

}