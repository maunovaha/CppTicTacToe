#pragma once

#include "../core/Surface.h"
#include "../core/Texture.h"
#include "../core/Component.h"
#include "../core/AppContext.h"
#include "../math/Rect.h"
#include <string>
#include <memory>

namespace engine::ui {

class Image: public core::Component {
public:
    Image(const core::Surface& surface)
        : texture_{core::AppContext::getRenderer(), surface} {}
    Image(const std::string& path, std::shared_ptr<math::Rect> clip = nullptr)
        : texture_{core::AppContext::getRenderer(), path}, clip_{std::move(clip)} {}
    void onRender() const override;
private:
    core::Texture texture_;
    std::shared_ptr<math::Rect> clip_;
};

}