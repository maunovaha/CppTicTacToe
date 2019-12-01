#include "Texture.h"
#include "Surface.h"
#include <stdexcept>

namespace SDL2wrap {

Texture::Texture(const Renderer& renderer, const std::string& image_path)
{
    const Surface surface{image_path};

    texture_ = UniqueTexturePtr{SDL_CreateTextureFromSurface(renderer.get(), surface.get())};

    if (!texture_) {
         throw std::runtime_error("Could not create texture, " + std::string{SDL_GetError()});
    }

    width_ = surface.width();
    height_ = surface.height();
}

void Texture::render(const Renderer& renderer, const SDL_Point& position, SDL_Rect* clip) const
{
    SDL_Rect render_quad{position.x, position.y, width_, height_};

    // Used for rendering only a smaller part of a larger texture, such as Texture atlas.
    if (clip) {
        render_quad.w = clip->w;
        render_quad.h = clip->h;
    }

    if (SDL_RenderCopy(renderer.get(), texture_.get(), clip, &render_quad) != 0) {
        throw std::runtime_error("Could not render a texture, " + std::string{SDL_GetError()});
    }
}

int Texture::width() const
{
    return width_;
}

int Texture::height() const
{
    return height_;
}

SDL_Texture* Texture::get() const
{
    return texture_.get();
}

}