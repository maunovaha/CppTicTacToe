#pragma once

#include "../sdl2wrap/Window.h"
#include "../sdl2wrap/Renderer.h"
#include <string>

namespace engine {

class Window {
public:
    Window(const std::string& title, const SDL_Rect& rect) 
        : window_{title, rect}
        , renderer_{window_, CLEAR_COLOR, RENDERER_FLAGS} {}
    void clear() const;
    void present() const;
    const sdl2wrap::Renderer& getRenderer() const;

    static constexpr Uint32 CENTERED = sdl2wrap::Window::CENTERED;
private:
    sdl2wrap::Window window_;
    sdl2wrap::Renderer renderer_;

    static constexpr SDL_Color WHITE = {0xFF, 0xFF, 0xFF, 0xFF};
    static constexpr SDL_Color CLEAR_COLOR = WHITE;
    static constexpr Uint32 RENDERER_FLAGS = sdl2wrap::Renderer::ACCELERATED | sdl2wrap::Renderer::PRESENTVSYNC;
};

}
