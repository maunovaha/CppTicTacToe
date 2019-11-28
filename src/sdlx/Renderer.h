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
    struct DestroyRenderer {
        void operator()(SDL_Renderer* renderer) const
        {
            SDL_DestroyRenderer(renderer);
        }
    };

    using UniqueRendererPtr = std::unique_ptr<SDL_Renderer, DestroyRenderer>;

    SDL_Color clear_color_;
    UniqueRendererPtr renderer_;
};

}

#endif