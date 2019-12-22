#include "Window.h"
#include <stdexcept>

namespace engine::core {

Window::Window(const std::string& title, const ui::Color& backgroundColor, const math::Rect& rect)
    : window_{SDL_CreateWindow(title.c_str(), rect.x, rect.y, rect.width, rect.height, SDL_WINDOW_SHOWN)}
{
    if (!window_) {
        throw std::runtime_error("Could not create window, " + std::string{SDL_GetError()});
    }

    renderer_ = std::make_unique<Renderer>(*this, backgroundColor, RENDERER_FLAGS);
}

math::Point Window::getSize() const
{
    int width = 0;
    int height = 0;

    SDL_GetWindowSize(window_.get(), &width, &height);

    return {width, height};
}

math::Point Window::getCenter() const
{
    const math::Point size = getSize();

    return {size.x / 2, size.y / 2};
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
