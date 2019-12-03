#include "Window.h"
#include <stdexcept>

namespace sdl2wrap {

Window::Window(const std::string& title, const SDL_Rect& rect)
    : window_{SDL_CreateWindow(title.c_str(), rect.x, rect.y, rect.w, rect.h, SDL_WINDOW_SHOWN)}
{
    if (!window_) {
        throw std::runtime_error("Could not create window, " + std::string{SDL_GetError()});
    }
}

SDL_Window* Window::get() const
{
    return window_.get();
}

}