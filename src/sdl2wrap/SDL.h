#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace sdl2wrap {

class SDL {
public:
    SDL(const Uint32 flags);
    ~SDL();

    static constexpr Uint32 video = SDL_INIT_VIDEO;
};

}
