#pragma once

#if defined(_WIN32)
#include <SDL.h>
#include <SDL_mixer.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#endif

namespace engine::core::sdl {

class SDLMixer {
public:
    SDLMixer();
    ~SDLMixer();
};

}