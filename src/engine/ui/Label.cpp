#include "Label.h"

namespace engine::ui {

void Label::render(const sdl2wrap::Renderer& renderer) const
{
    texture_.render(renderer, {x_, y_});
}

int Label::getWidth() const
{
    return texture_.getWidth();
}

int Label::getHeight() const
{
    return texture_.getHeight();
}

}