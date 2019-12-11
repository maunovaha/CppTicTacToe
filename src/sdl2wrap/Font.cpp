#include "Font.h"
#include <stdexcept>

namespace sdl2wrap {

Font::Font(const std::string& filePath, const int size)
{
    font_ = UniqueFont{TTF_OpenFont(filePath.c_str(), size)};

    if (!font_) {
        throw std::runtime_error("Could not create font, " + std::string{TTF_GetError()});
    }
}

Surface Font::renderBlended(const std::string& text, const SDL_Color& color) const
{
    SDL_Surface* surface = TTF_RenderText_Blended(font_.get(), text.c_str(), color);

    if (!surface) {
        throw std::runtime_error("Could not render solid text, " + std::string{TTF_GetError()});
    }

    return {surface};
}

TTF_Font* Font::get() const
{
    return font_.get();
}

}