#include "Sprite.h"

namespace engine {

void Sprite::render(const sdl2wrap::Renderer& renderer) const
{
    texture_.render(renderer, {x_, y_});
}

}