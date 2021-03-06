#pragma once

#if defined(_WIN32)
    #include <SDL.h>
    #include <SDL_ttf.h>
#else
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
#endif

namespace engine::core::sdl {

class SDLTTF {
public:
    SDLTTF();
    ~SDLTTF();
};

}