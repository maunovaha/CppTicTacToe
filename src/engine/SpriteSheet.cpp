#include "SpriteSheet.h"

namespace engine {

SpriteSheet::SpriteSheet(const sdl2wrap::Renderer& renderer,
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

std::shared_ptr<Sprite> SpriteSheet::getSprite(const SpriteName& spriteName) const
{
    if (!isLoaded(spriteName)) {
        throw std::runtime_error("Could not get sprite with name: " + spriteName);
    }

    return spriteSheetData_.at(spriteName);
}

bool SpriteSheet::isLoaded(const SpriteName& spriteName) const
{
    return spriteSheetData_.find(spriteName) != spriteSheetData_.end();
}

}