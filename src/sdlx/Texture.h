#ifndef SDLX_TEXTURE_H
#define SDLX_TEXTURE_H

#include "Renderer.h"
#include <SDL2/SDL.h>
#include <string>
#include <memory>

namespace sdlx {

class Texture {
public:
    Texture(const Renderer& renderer, const std::string& image_path);
    void render(const Renderer& renderer, const SDL_Point& position, SDL_Rect* clip = nullptr) const;
    int width() const;
    int height() const;
    SDL_Texture* get() const;
private:
    struct DestroyTexture {
        void operator()(SDL_Texture* texture) const
        {
            SDL_DestroyTexture(texture);
        }
    };

    using UniqueTexturePtr = std::unique_ptr<SDL_Texture, DestroyTexture>;

    int width_ = 0;
    int height_ = 0;
    UniqueTexturePtr texture_;
};

}

#endif