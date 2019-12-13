#pragma once

#include "../../sdl2wrap/Font.h"

namespace engine::ui {

class Font {
public:
    Font(const std::string& filePath, const int size) : font_{filePath, size} {}
    sdl2wrap::Surface renderBlended(const std::string& text, const SDL_Color& color) const;
private:
    sdl2wrap::Font font_;
};

}