#pragma once

#include "Sprite.h"
#include "../../sdl2wrap/Rect.h"
#include <memory>
#include <stdexcept>

namespace engine::_2d {

using SpriteName = std::string;
using SpriteClip = sdl2wrap::Rect;
using SharedSpriteClip = std::shared_ptr<SpriteClip>;
using SpriteSheetConfig = std::unordered_map<SpriteName, SharedSpriteClip>;

class SpriteSheet {
public:
    SpriteSheet(const sdl2wrap::Renderer& renderer,
                TextureCache& textureCache,
                const TexturePath& texturePath, 
                const SpriteSheetConfig& spriteSheetConfig);
    std::shared_ptr<Sprite> getSprite(const SpriteName& spriteName) const;
private:
    bool isLoaded(const SpriteName& spriteName) const;

    using SharedSprite = std::shared_ptr<Sprite>;
    using SpriteSheetData = std::unordered_map<SpriteName, SharedSprite>;

    SpriteSheetData spriteSheetData_;
};

}
