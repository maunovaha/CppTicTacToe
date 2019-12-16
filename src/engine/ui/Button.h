#pragma once

#include "Text.h"
#include "../sprite/Sprite.h"
#include "../io/Input.h"
#include <string>
#include <functional>
#include <cassert>

namespace engine::ui {

class Button : public scene::GameObject {
public:
    Button(std::string text,
           std::shared_ptr<Font> font,
           const Color& color,
           std::shared_ptr<sprite::Sprite> background,
           const int x,
           const int y,
           const gfx::Renderer& renderer)
        : GameObject{x, y}
        , background_{std::move(background)}
        , text_{std::make_unique<ui::Text>(std::move(text), std::move(font), color, 0, 0, renderer)}
    {
        background_->setPosition(x_, y_);
        // REFACTOR: The magic number is used atm. because the button graphic contains a shadow
        // underneath. Ofc. This should be removed later on.
        const int buttonShadowHeight = 2;
        const math::Point backgroundCenterPoint = background_->getCenterPoint();
        const math::Point textCenterPoint = text_->getCenterPoint();
        const int textY = y_ + backgroundCenterPoint.y - textCenterPoint.y - buttonShadowHeight;
        const int textX = x_ + backgroundCenterPoint.x - textCenterPoint.x;
        text_->setPosition(textX, textY);
    }

    void onUpdate() override
    {
        if (!onClickListener_ || !io::Input::getMouse().isButtonPressed(io::KeyCode::MouseLeft)) {
            return;
        }

        const math::Rect buttonBounds = background_->getBounds();
        const math::Point mouseClickPosition = io::Input::getMouse().getPosition();

        if (buttonBounds.contains(mouseClickPosition)) {
            onClickListener_();
        }
    }

    void onRender(const gfx::Renderer& renderer) const override
    {
        background_->onRender(renderer);
        text_->onRender(renderer);
    }

    void registerOnClickListener(std::function<void()> onClickListener)
    {
        assert(!onClickListener_);
        onClickListener_ = std::move(onClickListener);
    }
private:
    std::shared_ptr<sprite::Sprite> background_;
    std::unique_ptr<ui::Text> text_;
    std::function<void()> onClickListener_;
};

}