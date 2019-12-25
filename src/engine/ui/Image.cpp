#include "Image.h"
#include "../world/Transform.h"
#include <cassert>

namespace engine::ui {

void Image::onRender() const
{
    const world::Transform& transform = gameObject->getComponent<world::Transform>();
    texture_.render(core::AppContext::getRenderer(), transform.getWorldPosition());
}

math::Point Image::getSize() const
{
    return {texture_.getWidth(), texture_.getHeight()};
}

math::Point Image::getCenter() const
{
    const math::Point size = getSize();
    return {size.x / 2, size.y / 2};
}

}
