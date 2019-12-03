#pragma once

#include "Window.h"
#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif
#include <memory>

namespace sdl2wrap {

class Renderer {
public:
    Renderer(const Window& window, const SDL_Color& clearColor, const Uint32 flags);
    void setDrawColor(const SDL_Color& color) const;
    void clear() const;
    void present() const;
    SDL_Renderer* get() const;

    static constexpr Uint32 ACCELERATED  = SDL_RENDERER_ACCELERATED;
    static constexpr Uint32 PRESENTVSYNC = SDL_RENDERER_PRESENTVSYNC;
private:
    struct DestroyRenderer {
        void operator()(SDL_Renderer* renderer) const
        {
            SDL_DestroyRenderer(renderer);
        }
    };

    using UniqueRendererPtr = std::unique_ptr<SDL_Renderer, DestroyRenderer>;

    SDL_Color clearColor_;
    UniqueRendererPtr renderer_;
};

}
