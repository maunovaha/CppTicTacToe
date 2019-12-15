#include "Text.h"

namespace engine::ui {

void Text::render(const gfx::Renderer& renderer) const
{
    text_.render(renderer, {x_, y_});
}

int Text::getWidth() const
{
    return text_.getWidth();
}

int Text::getHeight() const
{
    return text_.getHeight();
}

}