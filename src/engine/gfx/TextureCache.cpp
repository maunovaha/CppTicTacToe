#include "TextureCache.h"

namespace engine::gfx {

const Texture& TextureCache::load(const Renderer& renderer, const TexturePath& texturePath)
{
    if (isCached(texturePath)) {
        return *(textureMap_.at(texturePath));
    }

    UniqueTexture texture = std::make_unique<Texture>(renderer, texturePath);
    return *(textureMap_.emplace(texturePath, std::move(texture)).first->second);
}

bool TextureCache::isCached(const TexturePath& texturePath) const
{
    return textureMap_.find(texturePath) != textureMap_.end();
}

}