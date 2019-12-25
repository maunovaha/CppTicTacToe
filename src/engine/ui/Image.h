#pragma once

#include "../core/Surface.h"
#include "../core/Texture.h"
#include "../core/Component.h"
#include "../core/AppContext.h"
#include "../math/Rect.h"
#include "../math/Point.h"
#include <string>
#include <memory>

namespace engine::ui {

class Image : public core::Component {
public:
    Image(const core::Surface& surface)
        : texture_{core::AppContext::getRenderer()
        , surface} {}
    Image(const std::string& path, 
          std::unique_ptr<math::Rect> clip = std::unique_ptr<math::Rect>{nullptr})
        : texture_{core::AppContext::getRenderer(), path}
        , clip_{std::move(clip)} {}
    void onRender() const override;
    int getWidth() const;
    int getHeight() const;
    math::Point getSize() const;
    math::Point getCenter() const;
    math::Rect getRect() const;
    math::Rect getWorldRect() const;
private:
    core::Texture texture_;
    std::unique_ptr<math::Rect> clip_;
};

}