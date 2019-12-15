#pragma once

#include "Renderer.h"
#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif
#include <string>
#include <memory>

namespace engine::gfx {

class Window {
public:
    Window(const std::string& title, const SDL_Rect& rect);
    const Renderer& getRenderer() const;
    SDL_Window* get() const;

    static constexpr Uint32 CENTERED = SDL_WINDOWPOS_CENTERED;
private:
    struct DestroyWindow {
        void operator()(SDL_Window* window) const
        {
            SDL_DestroyWindow(window);
        }
    };

    using UniqueWindow = std::unique_ptr<SDL_Window, DestroyWindow>;

    UniqueWindow window_;
    std::unique_ptr<Renderer> renderer_;

    static constexpr SDL_Color WHITE = {0xFF, 0xFF, 0xFF, 0xFF};
    static constexpr SDL_Color CLEAR_COLOR = WHITE;
    static constexpr Uint32 RENDERER_FLAGS = Renderer::ACCELERATED | Renderer::PRESENTVSYNC;
};

}
