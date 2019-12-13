#pragma once

#include "GameObject.h"
#include "TextureCache.h"
#include "../sdl2wrap/Texture.h"
#include "../sdl2wrap/Rect.h"
#include <string>

namespace engine {

class Sprite : public GameObject {
public:
    Sprite(const sdl2wrap::Renderer& renderer,
           TextureCache& textureCache,
           const TexturePath& texturePath,
           const int x = 0,
           const int y = 0,
           std::shared_ptr<sdl2wrap::Rect> clip = nullptr)
        : GameObject{x, y}
        , clip_{std::move(clip)}
        , texture_{textureCache.load(renderer, texturePath)} {}
    void render(const sdl2wrap::Renderer& renderer) const override;
    int getWidth() const;
    int getHeight() const;
private:
    std::shared_ptr<sdl2wrap::Rect> clip_;
    const sdl2wrap::Texture& texture_;
};

}