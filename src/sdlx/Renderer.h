#ifndef SDLX_RENDERER_H
#define SDLX_RENDERER_H

#include "Window.h"
#include <SDL2/SDL.h>

namespace sdlx {

class Renderer {
public:
    Renderer(const Window& window, const Uint32 flags);
    ~Renderer();
    void set_draw_color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) const;
    void clear() const;
    void present() const;
private:
    SDL_Renderer* renderer_ = nullptr;
};

}

#endif