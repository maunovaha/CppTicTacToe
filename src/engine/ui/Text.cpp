#include "Text.h"

namespace engine::ui {

void Text::render(const gfx::Renderer& renderer) const
{
    text_.render(renderer, {x_, y_});
}

math::Rect Text::getBounds() const
{
    return {x_, y_, text_.getWidth(), text_.getHeight()};
}

math::Point Text::getCenterPoint() const
{
    const math::Rect bounds = getBounds();
    return {bounds.width / 2, bounds.height / 2};
}

}