#ifndef SDLX_SDLX_H
#define SDLX_SDLX_H

#include <SDL2/SDL.h>

namespace sdlx {

class Sdlx {
public:
    Sdlx(const Uint32 flags);
    ~Sdlx();
};

}

#endif