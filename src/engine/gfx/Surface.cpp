#include "Surface.h"
#if defined(_WIN32)
    #include <SDL_image.h>
#else
    #include <SDL2/SDL_image.h>
#endif
#include <stdexcept>
#include <cassert>

namespace engine::gfx {

Surface::Surface(const std::string& imagePath) : surface_{IMG_Load(imagePath.c_str())}
{
    if (!surface_) {
        throw std::runtime_error("Could not create surface, " + std::string{IMG_GetError()});
    }

    // NOTE: Color keying is not used atm, because image saved as transparent .png seems to work
    // automatically. Hence, color keying were not really accurate when tested with couple of
    // images; Further investigation needed, whether it's because of the given sRGB profile
    // warning at the console window or not.

    // Makes all pixels in image transparent which matches the COLOR_KEY.
    // SDL_SetColorKey(surface_.get(), SDL_TRUE, SDL_MapRGB(surface_->format, COLOR_KEY.getRed(), 
    //     COLOR_KEY.getGreen(), COLOR_KEY.getBlue()));
}

Surface::Surface(SDL_Surface* surface) : surface_{surface}
{
    assert(surface_);
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