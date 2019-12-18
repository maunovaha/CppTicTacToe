#pragma once

#include "Font.h"
#include "../core/AppContext.h"
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
        const int y)
        : scene::GameObject{x, y}
        , font_{std::move(font)}
        , text_{core::AppContext::getRenderer(), font_->renderBlended(text, color)} {}
    void onRender() const override;
    int getWidth() const;
    int getHeight() const;
    math::Rect getBounds() const;
    math::Point getCenterPoint() const;
private:
    std::shared_ptr<Font> font_;
    gfx::Texture text_;
};

}
