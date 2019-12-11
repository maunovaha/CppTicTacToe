#include "SDL.h"
#include <stdexcept>
#include <string>

namespace sdl2wrap {

SDL::SDL(const Uint32 flags)
{
    static constexpr int SUCCESS_CODE = 0;

    if (SDL_Init(flags) != SUCCESS_CODE) {
        throw std::runtime_error("Could not init SDL, " + std::string{SDL_GetError()});
    }
}

SDL::~SDL()
{
    SDL_Quit();
}

}