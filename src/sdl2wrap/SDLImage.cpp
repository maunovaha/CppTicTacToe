#include "SDLImage.h"
#include <stdexcept>
#include <string>

namespace sdl2wrap {

SDLImage::SDLImage(const int flags)
{
    if (!(IMG_Init(flags) & flags)) {
        throw std::runtime_error("Could not init SDL_image, " + std::string{IMG_GetError()});
    }
}

SDLImage::~SDLImage()
{
    IMG_Quit();
}

}
