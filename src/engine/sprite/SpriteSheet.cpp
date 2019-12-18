#include "SpriteSheet.h"
#include <stdexcept>

namespace engine::sprite {

SpriteSheet::SpriteSheet(const std::string& imagePath, const Config& config)
{
    for (const auto& spriteConfig : config) {
        const SpriteName& spriteName = spriteConfig.first;
        const SharedSpriteClip& spriteClip = spriteConfig.second;

        auto sprite = std::make_shared<Sprite>(imagePath, 0, 0, spriteClip);
        spriteSheetData_.emplace(spriteName, std::move(sprite));
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