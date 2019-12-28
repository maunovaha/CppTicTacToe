#include "Button.h"
#include "../core/AppContext.h"
#include "../io/KeyCode.h"

namespace engine::ui {

Button::Button(const std::string& path, std::unique_ptr<math::Rect> clip) 
    : Image{path, std::move(clip)}
{
}

void Button::onUpdate()
{
    if (!onClickListener_ || !core::AppContext::getInput().isButtonPressed(io::KeyCode::MouseLeft)) {
        return;
    }

    const math::Point mousePosition = core::AppContext::getInput().getMouse().getPosition();

    if (getWorldRect().contains(mousePosition)) {
        onClickListener_();
    }
}

void Button::onRender() const
{
    Image::onRender();
}

}