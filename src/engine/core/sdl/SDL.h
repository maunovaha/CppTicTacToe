#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace engine::core::sdl {

class SDL {
public:
    SDL(const Uint32 flags);
    ~SDL();

    static constexpr Uint32 VIDEO = SDL_INIT_VIDEO;
    static constexpr Uint32 AUDIO = SDL_INIT_AUDIO;
};

}