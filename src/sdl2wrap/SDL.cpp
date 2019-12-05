#include "SDL.h"
#include <stdexcept>
#include <string>

namespace sdl2wrap {

SDL::SDL(const Uint32 flags)
{
    if (SDL_Init(flags) != 0) {
        throw std::runtime_error("Could not init SDL, " + std::string{SDL_GetError()});
    }
}

SDL::~SDL()
{
    SDL_Quit();
}

}