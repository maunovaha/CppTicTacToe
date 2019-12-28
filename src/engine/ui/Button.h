#pragma once

#include "Font.h"
#include "Color.h"
#include "Image.h"
#include "Text.h"
#include <string>
#include <functional>
#include <cassert>

namespace engine::ui {

class Button : public Image {
public:
    Button(const std::string& path, 
           std::unique_ptr<math::Rect> clip = std::unique_ptr<math::Rect>{nullptr});
    void onUpdate() override;
    void onRender() const override;

    template <class ClickListener>
    void registerOnClickListener(ClickListener onClickListener)
    {
        assert(!onClickListener_);
        onClickListener_ = std::move(onClickListener);
    }
private:
    std::function<void()> onClickListener_;
};

}
