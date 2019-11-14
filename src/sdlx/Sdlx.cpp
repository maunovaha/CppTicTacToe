#include "Sdlx.h"
#include <stdexcept>
#include <string>

namespace sdlx {

Sdlx::Sdlx(const Uint32 flags)
{
    if (SDL_Init(flags) != 0) {
        throw std::runtime_error("Could not initialize SDL, " + std::string{SDL_GetError()});
    }
}

Sdlx::~Sdlx()
{
    SDL_Quit();
}

}