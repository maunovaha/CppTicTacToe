#pragma once

#include "../scene/GameObject.h"
#include "../gfx/TextureCache.h"
#include "../gfx/Texture.h"
#include "../math/Rect.h"
#include <string>

namespace engine::sprite {

class Sprite : public scene::GameObject {
public:
    Sprite(const gfx::Renderer& renderer,
           gfx::TextureCache& textureCache,
           const gfx::TexturePath& texturePath,
           const int x,
           const int y,
           std::shared_ptr<math::Rect> clip = nullptr)
        : scene::GameObject{x, y}
        , clip_{std::move(clip)}
        , texture_{textureCache.load(renderer, texturePath)} {}
    void render(const gfx::Renderer& renderer) const override;
    int getWidth() const;
    int getHeight() const;
private:
    std::shared_ptr<math::Rect> clip_;
    const gfx::Texture& texture_;
};

}