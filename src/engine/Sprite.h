#pragma once

#include "GameObject.h"
#include "TextureCache.h"
#include "../sdl2wrap/Texture.h"
#include <string>

namespace engine {

class Sprite : public GameObject {
public:
    Sprite(const sdl2wrap::Renderer& renderer,
           TextureCache& textureCache,
           const TexturePath& texturePath,
           const int x = 0,
           const int y = 0) 
        : GameObject{x, y}
        , texture_{textureCache.load(renderer, texturePath)} {}
    void render(const sdl2wrap::Renderer& renderer) const override;
private:
    const sdl2wrap::Texture& texture_;
};

}