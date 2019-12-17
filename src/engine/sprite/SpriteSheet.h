#pragma once

#include "Sprite.h"
#include "../math/Rect.h"
#include <memory>
#include <stdexcept>

namespace engine::sprite {

class SpriteSheet {
public:
    using SpriteName = std::string;
    using SpriteClip = std::shared_ptr<math::Rect>;
    using Config     = std::unordered_map<SpriteName, SpriteClip>;

    SpriteSheet(const gfx::Renderer& renderer,
                gfx::TextureCache& textureCache,
                const std::string& imagePath,
                const Config& config);
    std::shared_ptr<Sprite> getSprite(const SpriteName& spriteName) const;
private:
    bool isLoaded(const SpriteName& spriteName) const;

    using SharedSprite    = std::shared_ptr<Sprite>;
    using SpriteSheetData = std::unordered_map<SpriteName, SharedSprite>;

    SpriteSheetData spriteSheetData_;
};

}
