#pragma once

#include "Renderer.h"
#include "Texture.h"
#include <unordered_map>
#include <string>

namespace engine::gfx {

using TexturePath = std::string;

class TextureCache {
public:
    const Texture& load(const Renderer& renderer, const TexturePath& texturePath);
private:
    bool isCached(const TexturePath& texturePath) const;

    using UniqueTexture = std::unique_ptr<Texture>;
    using TextureMap = std::unordered_map<TexturePath, UniqueTexture>;

    TextureMap textureMap_;
};

}