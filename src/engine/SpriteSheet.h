#pragma once

#include "Sprite.h"
#include "../sdl2wrap/Rect.h"
#include <memory>
#include <stdexcept>

namespace engine {

using SpriteName = std::string;
using SpriteClip = sdl2wrap::Rect;
using SharedSpriteClip = std::shared_ptr<SpriteClip>;
using SpriteSheetConfig = std::unordered_map<SpriteName, SharedSpriteClip>;

class SpriteSheet {
public:
    SpriteSheet(const sdl2wrap::Renderer& renderer,
                TextureCache& textureCache,
                const TexturePath& texturePath, 
                const SpriteSheetConfig& spriteSheetConfig)
    {
        for (const auto& spriteConfig : spriteSheetConfig) {
            SharedSprite sprite = std::make_shared<Sprite>(renderer, textureCache, texturePath, 
                0, 0, spriteConfig.second);
            spriteSheetData_.emplace(spriteConfig.first, std::move(sprite));
        }
    }

    std::shared_ptr<Sprite> getSprite(const SpriteName& spriteName) const
    {
        if (!isLoaded(spriteName)) {
            throw std::runtime_error("Could not get sprite with name: " + spriteName);
        }

        return spriteSheetData_.at(spriteName);
    }
private:
    bool isLoaded(const SpriteName& spriteName) const
    {
        return spriteSheetData_.find(spriteName) != spriteSheetData_.end();
    }

    using SharedSprite = std::shared_ptr<Sprite>;
    using SpriteSheetData = std::unordered_map<SpriteName, SharedSprite>;

    SpriteSheetData spriteSheetData_;
};

}
