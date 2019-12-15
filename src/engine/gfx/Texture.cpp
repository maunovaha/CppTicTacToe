#include "Texture.h"
#include <stdexcept>

namespace engine::gfx {

Texture::Texture(const Renderer& renderer, const Surface& surface)
{
    texture_ = UniqueTexture{SDL_CreateTextureFromSurface(renderer.get(), surface.get())};

    if (!texture_) {
        throw std::runtime_error("Could not create texture, " + std::string{SDL_GetError()});
    }

    width_ = surface.getWidth();
    height_ = surface.getHeight();
}

void Texture::render(const Renderer& renderer, const SDL_Point& position, math::Rect* clip) const
{
    SDL_Rect renderQuad{position.x, position.y, width_, height_};

    // Used for rendering only a smaller part of a larger texture (e.g. SpriteSheet)
    if (clip) {
        renderQuad.w = clip->width;
        renderQuad.h = clip->height;
    }

    if (SDL_RenderCopy(renderer.get(), texture_.get(), reinterpret_cast<SDL_Rect*>(clip), &renderQuad) != 0) {
        throw std::runtime_error("Could not render a texture, " + std::string{SDL_GetError()});
    }
}

int Texture::getWidth() const
{
    return width_;
}

int Texture::getHeight() const
{
    return height_;
}

SDL_Texture* Texture::get() const
{
    return texture_.get();
}

}