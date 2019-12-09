#pragma once

#include "../sdl2wrap/Renderer.h"
#include "../sdl2wrap/Texture.h"
#include <unordered_map>
#include <string>

namespace engine {

using TexturePath = std::string;

class TextureCache {
public:
    const sdl2wrap::Texture& load(const sdl2wrap::Renderer& renderer, 
                                  const TexturePath& texturePath);
private:
    bool is_cached(const TexturePath& texturePath) const;

    using UniqueTexture = std::unique_ptr<sdl2wrap::Texture>;
    using TextureMap = std::unordered_map<TexturePath, UniqueTexture>;

    TextureMap textureMap_;
};

}