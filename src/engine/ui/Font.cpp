#include "Font.h"

namespace engine::ui {

sdl2wrap::Surface Font::renderBlended(const std::string& text, const SDL_Color& color) const
{
    return font_.renderBlended(text, color);
}

}