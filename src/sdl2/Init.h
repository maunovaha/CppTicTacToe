#ifndef SDL2_INIT_H
#define SDL2_INIT_H

#if defined(_WIN32)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

namespace sdl2 {

class Init {
public:
    Init(const Uint32 flags);
    ~Init();

    static constexpr Uint32 video = SDL_INIT_VIDEO;
};

}

#endif