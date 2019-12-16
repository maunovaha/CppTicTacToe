#pragma once

#include "Text.h"
#include "../sprite/Sprite.h"
#include <string>
#include <functional>

namespace engine::ui {

class Button : public scene::GameObject {
public:
    Button(std::string text,
           std::shared_ptr<Font> font,
           const Color& color,
           std::shared_ptr<sprite::Sprite> background,
           const int x,
           const int y,
           const gfx::Renderer& renderer);
    void onUpdate() override;
    void onRender(const gfx::Renderer& renderer) const override;
    void registerOnClickListener(std::function<void()> onClickListener);
private:
    std::shared_ptr<sprite::Sprite> background_;
    std::unique_ptr<ui::Text> text_;
    std::function<void()> onClickListener_;
};

}