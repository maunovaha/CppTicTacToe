#include "Sprite.h"

namespace engine::sprite {

void Sprite::render(const gfx::Renderer& renderer) const
{
    texture_.render(renderer, {x_, y_}, clip_.get());
}

int Sprite::getWidth() const
{
    if (clip_) {
        return clip_->width;
    }

    return texture_.getWidth();
}

int Sprite::getHeight() const
{
    if (clip_) {
        return clip_->height;
    }

    return texture_.getHeight();
}

}