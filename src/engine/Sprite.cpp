#include "Sprite.h"

namespace engine {

void Sprite::render(const sdl2wrap::Renderer& renderer) const
{
    texture_.render(renderer, {x_, y_}, clip_.get());
}

int Sprite::getWidth() const
{
    if (clip_) {
        return clip_->w;
    }

    return texture_.getWidth();
}

int Sprite::getHeight() const
{
    if (clip_) {
        return clip_->h;
    }

    return texture_.getHeight();
}

}