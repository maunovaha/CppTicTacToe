#include "Texture.h"
#include "Surface.h"
#include <stdexcept>

namespace sdl2wrap {

Texture::Texture(const Renderer& renderer, const std::string& imagePath)
{
    const Surface surface{imagePath};

    texture_ = UniqueTexturePtr{SDL_CreateTextureFromSurface(renderer.get(), surface.get())};

    if (!texture_) {
         throw std::runtime_error("Could not create texture, " + std::string{SDL_GetError()});
    }

    width_ = surface.getWidth();
    height_ = surface.getHeight();
}

void Texture::render(const Renderer& renderer, const SDL_Point& position, SDL_Rect* clip) const
{
    SDL_Rect renderQuad{position.x, position.y, width_, height_};

    // Used for rendering only a smaller part of a larger texture, such as Texture atlas.
    if (clip) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    if (SDL_RenderCopy(renderer.get(), texture_.get(), clip, &renderQuad) != 0) {
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