#pragma once

#include "Sprite.h"
#include "../math/Rect.h"

namespace engine::sprite {

class SpriteSheet {
public:
    using SpriteName = std::string;
    using SpriteClip = math::Rect;
    using SharedSpriteClip = std::shared_ptr<SpriteClip>;
    using Config = std::unordered_map<SpriteName, SharedSpriteClip>;

    SpriteSheet(const std::string& imagePath, const Config& config);
    std::shared_ptr<Sprite> getSprite(const SpriteName& spriteName) const;
private:
    bool isLoaded(const SpriteName& spriteName) const;

    using SpriteSheetData = std::unordered_map<SpriteName, std::shared_ptr<Sprite>>;
    SpriteSheetData spriteSheetData_;
};

}
