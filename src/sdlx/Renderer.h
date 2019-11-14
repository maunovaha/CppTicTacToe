#ifndef SDLX_RENDERER_H
#define SDLX_RENDERER_H

#include "Window.h"
#include <SDL2/SDL.h>

namespace sdlx {

class Renderer {
public:
    Renderer(const Window& window, const SDL_Color& clear_color, const Uint32 flags);
    ~Renderer();
    void set_draw_color(const SDL_Color& color) const;
    void clear() const;
    void present() const;
    SDL_Renderer* get() const;
private:
    SDL_Color clear_color_;
    SDL_Renderer* renderer_ = nullptr;
};

}

#endif