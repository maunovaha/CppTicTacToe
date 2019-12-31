#include "SDLMixer.h"
#include <stdexcept>
#include <string>

namespace engine::core::sdl {

SDLMixer::SDLMixer()
{
    static constexpr int SUCCESS_CODE = 0;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != SUCCESS_CODE) {
        throw std::runtime_error("Could not init SDL_mixer, " + std::string{Mix_GetError()});
    }
}

SDLMixer::~SDLMixer()
{
    Mix_Quit();
}

}