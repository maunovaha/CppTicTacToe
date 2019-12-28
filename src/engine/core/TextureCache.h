#pragma once

#include "Renderer.h"
#include "Texture.h"
#include <unordered_map>
#include <string>

namespace engine::core {

class TextureCache {
public:
    const Texture& load(const std::string& texturePath);
private:
    bool isCached(const std::string& texturePath) const;

    using UniqueTexture = std::unique_ptr<Texture>;
    using TextureMap    = std::unordered_map<std::string, UniqueTexture>;

    TextureMap textureMap_;
};

}