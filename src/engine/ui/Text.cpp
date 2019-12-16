#include "Text.h"

namespace engine::ui {

void Text::onRender(const gfx::Renderer& renderer, const math::Point& parentPosition) const
{
    text_.render(renderer, {parentPosition.x + x, parentPosition.y + y});
}

int Text::getWidth() const
{
    return text_.getWidth();
}

int Text::getHeight() const
{
    return text_.getHeight();
}

math::Rect Text::getBounds() const
{
    return {x, y, getWidth(), getHeight()};
}

math::Point Text::getCenterPoint() const
{
    return {getWidth() / 2, getHeight() / 2};
}

}