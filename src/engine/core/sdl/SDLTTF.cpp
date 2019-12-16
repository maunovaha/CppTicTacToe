#include "SDLTTF.h"
#include <stdexcept>
#include <string>

namespace engine::core::sdl {

SDLTTF::SDLTTF()
{
    static constexpr int SUCCESS_CODE = 0;

    if (TTF_Init() != SUCCESS_CODE) {
        throw std::runtime_error("Could not init SDL_ttf, " + std::string{TTF_GetError()});
    }
}

SDLTTF::~SDLTTF()
{
    TTF_Quit();
}

}