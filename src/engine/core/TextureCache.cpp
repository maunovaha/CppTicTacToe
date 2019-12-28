#include "TextureCache.h"
#include "../core/AppContext.h"

namespace engine::core {

const Texture& TextureCache::load(const std::string& texturePath)
{
    if (isCached(texturePath)) {
        return *(textureMap_.at(texturePath));
    }

    UniqueTexture texture = std::make_unique<Texture>(core::AppContext::getRenderer(), texturePath);
    return *(textureMap_.emplace(texturePath, std::move(texture)).first->second);
}

bool TextureCache::isCached(const std::string& texturePath) const
{
    return textureMap_.find(texturePath) != textureMap_.end();
}

}