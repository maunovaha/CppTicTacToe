#include "Sdlx.h"
#include <SDL2/SDL_image.h>
#include <stdexcept>
#include <string>

namespace sdl2 {

Sdlx::Sdlx(const Uint32 flags)
{
    if (SDL_Init(flags) != 0) {
        throw std::runtime_error("Could not init SDL, " + std::string{SDL_GetError()});
    }

    int img_flags = IMG_INIT_PNG;

    if (!(IMG_Init(img_flags) & img_flags)) {
        throw std::runtime_error("Could not init SDL_image, " + std::string{IMG_GetError()});
    }
}

Sdlx::~Sdlx()
{
    IMG_Quit();
    SDL_Quit();
}

}
