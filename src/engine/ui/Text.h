#pragma once

#include "Font.h"
#include "Color.h"
#include "Image.h"
#include <string>

namespace engine::ui {

class Text : public Image {
public:
    Text(const std::string& text, const Font& font, const Color& color)
        : Image{font.renderBlended(text, color)} {}
};

}
