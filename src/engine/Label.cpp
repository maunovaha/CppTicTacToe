#include "Label.h"

namespace engine {

void Label::render(const sdl2wrap::Renderer& renderer) const
{
    texture_.render(renderer, {x_, y_});
}

}