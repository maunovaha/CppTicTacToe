#ifndef SDL2WRAP_SDL_IMAGE_H
#define SDL2WRAP_SDL_IMAGE_H

#if defined(_WIN32)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

namespace SDL2wrap {

class SDLImage {
public:
    SDLImage(const int flags);
    ~SDLImage();

    static constexpr int png = IMG_INIT_PNG;
};

}

#endif