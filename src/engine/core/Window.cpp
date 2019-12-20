#include "Window.h"
#include <stdexcept>

namespace engine::core {

Window::Window(const std::string& title, const ui::Color& backgroundColor, const math::Rect& rect)
    : window_{SDL_CreateWindow(title.c_str(), rect.x, rect.y, rect.width, rect.height, SDL_WINDOW_SHOWN)}
    , bounds_{rect}
{
    if (!window_) {
        throw std::runtime_error("Could not create window, " + std::string{SDL_GetError()});
    }

    renderer_ = std::make_unique<Renderer>(*this, backgroundColor, RENDERER_FLAGS);
}

const Renderer& Window::getRenderer() const
{
    return *renderer_;
}

int Window::getWidth() const
{
    return bounds_.width;
}

int Window::getHeight() const
{
    return bounds_.height;
}

const math::Rect& Window::getBounds() const
{
    return bounds_;
}

math::Point Window::getCenterPoint() const
{
    return {bounds_.width / 2, bounds_.height / 2};
}

SDL_Window* Window::get() const
{
    return window_.get();
}

}
