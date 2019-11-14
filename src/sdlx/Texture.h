#ifndef SDLX_TEXTURE_H
#define SDLX_TEXTURE_H

#include "Renderer.h"
#include <SDL2/SDL.h>
#include <string>

namespace sdlx {

class Texture {
public:
    Texture(const Renderer& renderer, const std::string& image_path);
    ~Texture();
    void render(const Renderer& renderer, const SDL_Point& position, SDL_Rect* clip = nullptr) const;
    int width() const;
    int height() const;
    SDL_Texture* get() const;
private:
    int width_ = 0;
    int height_ = 0;
    SDL_Texture* texture_ = nullptr;
};

}

#endif