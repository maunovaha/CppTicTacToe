#include "Renderer.h"
#include <stdexcept>

namespace sdlx {

Renderer::Renderer(const Window& window, const Uint32 flags)
{
    renderer_ = SDL_CreateRenderer(window.get(), -1, flags);

    if (!renderer_) {
        throw std::runtime_error("Could not create renderer, " + std::string{SDL_GetError()});
    }
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
}

void Renderer::set_draw_color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) const
{
    if (SDL_SetRenderDrawColor(renderer_, red, green, blue, alpha) != 0) {
        throw std::runtime_error("Could not set renderer draw color, " + std::string{SDL_GetError()});
    }
}

void Renderer::clear() const
{
    set_draw_color(0xFF, 0xFF, 0xFF, 0xFF);

    if (SDL_RenderClear(renderer_) != 0) {
        throw std::runtime_error("Could not clear renderer, " + std::string{SDL_GetError()});
    }
}

void Renderer::present() const
{
    SDL_RenderPresent(renderer_);
}

}