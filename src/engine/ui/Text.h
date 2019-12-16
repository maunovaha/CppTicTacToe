#pragma once

#include "Font.h"
#include "../scene/GameObject.h"
#include "../gfx/Texture.h"
#include <string>
#include <memory>

namespace engine::ui {

class Text : public scene::GameObject {
public:
    Text(const std::string& text,
        std::shared_ptr<Font> font,
        const Color& color,
        const int x,
        const int y,
        const gfx::Renderer& renderer)
        : scene::GameObject{x, y}
        , font_{std::move(font)}
        , text_{renderer, font_->renderBlended(text, color)} {}
    void render(const gfx::Renderer& renderer) const override;
    math::Rect getBounds() const;
    math::Point getCenterPoint() const;
private:
    std::shared_ptr<Font> font_;
    gfx::Texture text_;
};

}
