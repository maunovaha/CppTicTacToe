#pragma once

#include "Text.h"
#include "../sprite/Sprite.h"
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
           const int y);
    void onUpdate() override;
    void onRender(const math::Point& parentPosition) const override;
    int getWidth() const;
    int getHeight() const;
    math::Rect getBounds() const;
    math::Point getCenterPoint() const;

    template <class ClickListener>
    void registerOnClickListener(ClickListener onClickListener)
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