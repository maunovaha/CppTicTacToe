#pragma once

#include "../scene/GameObject.h"
#include "../core/AppContext.h"
#include <string>

namespace engine::sprite {

class Sprite : public scene::GameObject {
public:
    Sprite(const std::string& imagePath,
           const int x,
           const int y,
           std::shared_ptr<math::Rect> clip = nullptr)
        : scene::GameObject{x, y}
        , clip_{std::move(clip)}
        , texture_{core::AppContext::getTextureCache().load(imagePath)} {}
    void onRender() const override;
    int getWidth() const;
    int getHeight() const;
    math::Rect getBounds() const;
    math::Point getCenterPoint() const;
private:
    std::shared_ptr<math::Rect> clip_;
    const gfx::Texture& texture_;
};

}