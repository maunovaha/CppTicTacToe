#include "Sprite.h"

namespace engine::sprite {

void Sprite::render(const gfx::Renderer& renderer) const
{
    texture_.render(renderer, {x_, y_}, clip_.get());
}

math::Rect Sprite::getBounds() const
{
    if (clip_) {
        return {x_, y_, clip_->width, clip_->height};
    }
    return {x_, y_, texture_.getWidth(), texture_.getHeight()};
}

math::Point Sprite::getCenterPoint() const
{
    const math::Rect bounds = getBounds();
    return {bounds.width / 2, bounds.height / 2};
}

}