#include "Sprite.h"

namespace engine::sprite {

void Sprite::onRender(const gfx::Renderer& renderer, const math::Point& parentPosition) const
{
    texture_.render(renderer, {parentPosition.x + x, parentPosition.y + y}, clip_.get());
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

math::Rect Sprite::getBounds() const
{
    return {x, y, getWidth(), getHeight()};
}

math::Point Sprite::getCenterPoint() const
{
    return {getWidth() / 2, getHeight() / 2};
}

}