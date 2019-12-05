#pragma once

#include "GameObject.h"
#include "../sdl2wrap/Texture.h"
#include <string>

namespace engine {

class Sprite : public GameObject {
public:
    Sprite(const sdl2wrap::Renderer& renderer,
           const std::string& imagePath,
           const int x = 0,
           const int y = 0)
        : GameObject{x, y}
        , texture_{renderer, imagePath} {}
    void render(const sdl2wrap::Renderer& renderer) const override;
private:
    // REFACTOR: Atm. we waste resources because every sprite has its own instance of the texture.
    // In reality, we should probably use some sort of SpriteCache or similar approach? E.g.
    // if some image is loaded once, we should not load it again, but use pointer instead.
    sdl2wrap::Texture texture_;
};

}