#pragma once

#include "GameObject.h"
#include "Font.h"
#include "../sdl2wrap/Texture.h"
#include <string>

namespace engine {

class Label : public GameObject {
public:
    Label(const sdl2wrap::Renderer& renderer,
          std::shared_ptr<Font> font,
          const std::string& text, 
          const SDL_Color& color,
          const int x = 0, 
          const int y = 0)
        : GameObject{x, y}
        , font_{std::move(font)}
        , texture_{renderer, font_->renderBlended(text, color)} {}
    void render(const sdl2wrap::Renderer& renderer) const override;
    int getWidth() const;
    int getHeight() const;
private:
    std::shared_ptr<Font> font_;
    sdl2wrap::Texture texture_;
};

}
