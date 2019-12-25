#include "Image.h"
#include "../world/Transform.h"
#include <cassert>

namespace engine::ui {

void Image::onRender() const
{
    const world::Transform& transform = gameObject->getComponent<world::Transform>();
    texture_.render(core::AppContext::getRenderer(), transform.getWorldPosition(), clip_.get());
}

int Image::getWidth() const
{
    if (clip_) {
        return clip_->width;
    }

    return texture_.getWidth();
}

int Image::getHeight() const
{
    if (clip_) {
        return clip_->height;
    }

    return texture_.getHeight();
}

math::Point Image::getSize() const
{
    return {getWidth(), getHeight()};
}

math::Point Image::getCenter() const
{
    const math::Point size = getSize();
    return {size.x / 2, size.y / 2};
}

math::Rect Image::getRect() const
{
    const world::Transform& transform = gameObject->getComponent<world::Transform>();
    const math::Point localPosition = transform.localPosition;

    return {localPosition.x, localPosition.y, getWidth(), getHeight()};
}

math::Rect Image::getWorldRect() const
{
    const world::Transform& transform = gameObject->getComponent<world::Transform>();
    const math::Point worldPosition = transform.getWorldPosition();

    return {worldPosition.x, worldPosition.y, getWidth(), getHeight()};
}

}
