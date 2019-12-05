#include "Window.h"

namespace engine {

void Window::clear() const
{
    renderer_.clear();
}

void Window::present() const
{
    renderer_.present();
}

const sdl2wrap::Renderer& Window::getRenderer() const
{
    return renderer_;
}

}