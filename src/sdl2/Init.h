#ifndef SDL2_INIT_H
#define SDL2_INIT_H

#include <SDL2/SDL.h>

namespace sdl2 {

class Init {
public:
    Init(const Uint32 flags);
    ~Init();

    static constexpr Uint32 video = SDL_INIT_VIDEO;
};

}

#endif