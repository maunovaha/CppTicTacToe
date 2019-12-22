#include "Image.h"
#include "RectTransform.h"
#include <cassert>

namespace engine::ui {

void Image::onRender() const
{
    assert(gameObject->hasComponent<RectTransform>());

    const auto& transform = gameObject->getComponent<RectTransform>();
    texture_.render(core::AppContext::getRenderer(), transform.getWorldPosition());
}

}
