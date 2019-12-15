#include "Window.h"
#include <stdexcept>

namespace engine::gfx {

Window::Window(const std::string& title, const SDL_Rect& rect)
    : window_{SDL_CreateWindow(title.c_str(), rect.x, rect.y, rect.w, rect.h, SDL_WINDOW_SHOWN)}
{
    if (!window_) {
        throw std::runtime_error("Could not create window, " + std::string{SDL_GetError()});
    }

    renderer_ = std::make_unique<Renderer>(*this, CLEAR_COLOR, RENDERER_FLAGS);
}

const Renderer& Window::getRenderer() const
{
    return *renderer_;
}

SDL_Window* Window::get() const
{
    return window_.get();
}

}
