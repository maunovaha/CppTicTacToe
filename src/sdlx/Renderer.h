#ifndef SDLX_RENDERER_H
#define SDLX_RENDERER_H

#include "Window.h"
#include <SDL2/SDL.h>
#include <memory>

namespace sdlx {

class Renderer {
public:
    Renderer(const Window& window, const SDL_Color& clear_color, const Uint32 flags);
    void set_draw_color(const SDL_Color& color) const;
    void clear() const;
    void present() const;
    SDL_Renderer* get() const;
private:
    SDL_Color clear_color_;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer_;
};

}

#endif