#include "Sprite.h"

namespace engine::sprite {

void Sprite::onRender() const
{
    int relativeX = x;
    int relativeY = y;

    if (parent) {
        relativeX += parent->x;
        relativeY += parent->y;
    }

    texture_.render(core::AppContext::getRenderer(), {relativeX, relativeY}, clip_.get());
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