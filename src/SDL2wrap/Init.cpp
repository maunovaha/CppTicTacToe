#include "Init.h"
#include <stdexcept>
#include <string>

namespace SDL2wrap {

Init::Init(const Uint32 flags)
{
    if (SDL_Init(flags) != 0) {
        throw std::runtime_error("Could not init SDL, " + std::string{SDL_GetError()});
    }
}

Init::~Init()
{
    SDL_Quit();
}

}
