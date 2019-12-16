#pragma once

#include "Sprite.h"
#include "../math/Rect.h"
#include <memory>
#include <stdexcept>

namespace engine::sprite {

using SpriteName        = std::string;
using SpriteClip        = math::Rect;
using SharedSpriteClip  = std::shared_ptr<SpriteClip>;
using SpriteSheetConfig = std::unordered_map<SpriteName, SharedSpriteClip>;

class SpriteSheet {
public:
    SpriteSheet(const gfx::Renderer& renderer,
                gfx::TextureCache& textureCache,
                const gfx::TexturePath& texturePath,
                const SpriteSheetConfig& spriteSheetConfig);
    std::shared_ptr<Sprite> getSprite(const SpriteName& spriteName) const;
private:
    bool isLoaded(const SpriteName& spriteName) const;

    using SharedSprite    = std::shared_ptr<Sprite>;
    using SpriteSheetData = std::unordered_map<SpriteName, SharedSprite>;

    SpriteSheetData spriteSheetData_;
};

}
