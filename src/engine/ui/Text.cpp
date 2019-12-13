#include "Text.h"

namespace engine::ui {

void Text::render(const sdl2wrap::Renderer& renderer) const
{
    texture_.render(renderer, {x_, y_});
}

int Text::getWidth() const
{
    return texture_.getWidth();
}

int Text::getHeight() const
{
    return texture_.getHeight();
}

}