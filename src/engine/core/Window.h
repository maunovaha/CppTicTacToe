#pragma once

#include "../math/Rect.h"
#include "Renderer.h"
#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif
#include <string>
#include <memory>

namespace engine::core {

class Window {
public:
    Window(const std::string& title, const ui::Color& backgroundColor, const math::Rect& rect);
    const Renderer& getRenderer() const;
    int getWidth() const;
    int getHeight() const;
    const math::Rect& getBounds() const;
    math::Point getCenterPoint() const;
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
    math::Rect bounds_;

    static constexpr ui::Color WHITE = {0xFF, 0xFF, 0xFF, 0xFF}; // REFACTOR: Move to ui::Color
    static constexpr ui::Color CLEAR_COLOR = WHITE; // REFACTOR: Make this as ui::Color::WHITE;
    static constexpr Uint32 RENDERER_FLAGS = Renderer::ACCELERATED | Renderer::PRESENTVSYNC;
};

}
