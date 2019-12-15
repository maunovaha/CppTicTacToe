#include "Renderer.h"
#include "Window.h"
#include <stdexcept>
#include <string>

namespace engine::gfx {

Renderer::Renderer(const Window& window, const ui::Color& clearColor, const Uint32 flags) 
    : clearColor_{clearColor}
    , renderer_{SDL_CreateRenderer(window.get(), -1, flags)}
{
    if (!renderer_) {
        throw std::runtime_error("Could not create renderer, " + std::string{SDL_GetError()});
    }
}

void Renderer::setDrawColor(const ui::Color& color) const
{
    if (SDL_SetRenderDrawColor(renderer_.get(), color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha()) != 0) {
        throw std::runtime_error("Could not set renderer draw color, " + std::string{SDL_GetError()});
    }
}

void Renderer::clear() const
{
    setDrawColor(clearColor_);

    if (SDL_RenderClear(renderer_.get()) != 0) {
        throw std::runtime_error("Could not clear renderer, " + std::string{SDL_GetError()});
    }
}

void Renderer::present() const
{
    SDL_RenderPresent(renderer_.get());
}

SDL_Renderer* Renderer::get() const
{
    return renderer_.get();
}

}