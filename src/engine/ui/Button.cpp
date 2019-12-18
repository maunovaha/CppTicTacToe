#include "Button.h"

namespace engine::ui {

Button::Button(std::string text,
               std::shared_ptr<Font> font,
               const Color& color,
               std::shared_ptr<sprite::Sprite> background,
               const int x,
               const int y)
    : GameObject{x, y}
    , background_{std::move(background)}
    , text_{std::make_shared<ui::Text>(std::move(text), std::move(font), color, 0, 0)}
{
    background_->setPosition(x, y);
    background_->parent = this;
    // Refactor: The magic number is used atm. because the button graphic contains a shadow
    // underneath. Ofc. This should be removed later on.
    const int buttonShadowHeight = 2;
    const math::Point backgroundCenterPoint = background_->getCenterPoint();
    const math::Point textCenterPoint = text_->getCenterPoint();
    const int textY = y + backgroundCenterPoint.y - textCenterPoint.y - buttonShadowHeight;
    const int textX = x + backgroundCenterPoint.x - textCenterPoint.x;
    text_->setPosition(textX, textY);
    text_->parent = this;
}

void Button::onUpdate()
{
    if (!onClickListener_ || !core::AppContext::getInput().isButtonPressed(io::KeyCode::MouseLeft)) {
        return;
    }

    const math::Point mouseClickPosition = core::AppContext::getInput().getMouse().getPosition();

    if (getBounds().contains(mouseClickPosition)) {
        onClickListener_();
    }
}

void Button::onRender() const
{
    background_->onRender();
    text_->onRender();
}

int Button::getWidth() const
{
    return background_->getWidth();
}

int Button::getHeight() const
{
    return background_->getHeight();
}

math::Rect Button::getBounds() const
{
    return {x, y, getWidth(), getHeight()};
}

math::Point Button::getCenterPoint() const
{
    return background_->getCenterPoint();
}

}