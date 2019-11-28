#include "Surface.h"
#include <SDL2/SDL_image.h>
#include <stdexcept>

namespace sdlx {

Surface::Surface(const std::string& image_path) : surface_{IMG_Load(image_path.c_str())}
{
    if (!surface_) {
        throw std::runtime_error("Could not create surface, " + std::string{IMG_GetError()});
    }
}

int Surface::width() const
{
    return surface_->w;
}

int Surface::height() const
{
    return surface_->h;
}

SDL_Surface* Surface::get() const
{
    return surface_.get();
}

}