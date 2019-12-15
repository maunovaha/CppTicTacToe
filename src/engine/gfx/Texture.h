#pragma once

#include "Renderer.h"
#include "Surface.h"
#include "../math/Rect.h"
#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif
#include <string>
#include <memory>

namespace engine::gfx {

class Texture {
public:
    Texture(const Renderer& renderer, const Surface& surface);
    Texture(const Renderer& renderer, const std::string& imagePath)
        : Texture{renderer, Surface{imagePath}} {}
    void render(const Renderer& renderer, const SDL_Point& position, math::Rect* clip = nullptr) const;
    int getWidth() const;
    int getHeight() const;
    SDL_Texture* get() const;
private:
    struct DestroyTexture {
        void operator()(SDL_Texture* texture) const
        {
            SDL_DestroyTexture(texture);
        }
    };

    using UniqueTexture = std::unique_ptr<SDL_Texture, DestroyTexture>;

    int width_ = 0;
    int height_ = 0;
    UniqueTexture texture_;
};

}