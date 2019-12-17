#include "SpriteSheet.h"

namespace engine::sprite {

SpriteSheet::SpriteSheet(const gfx::Renderer& renderer,
                         gfx::TextureCache& textureCache,
                         const std::string& imagePath,
                         const Config& config)
{
    for (const auto& spriteConfig : config) {
        SharedSprite sprite = std::make_shared<Sprite>(
            renderer, textureCache, imagePath, 0, 0, spriteConfig.second
        );
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