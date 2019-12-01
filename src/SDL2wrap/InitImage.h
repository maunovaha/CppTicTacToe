#ifndef SDL2WRAP_INIT_IMAGE_H
#define SDL2WRAP_INIT_IMAGE_H

#if defined(_WIN32)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

namespace SDL2wrap {

class InitImage {
public:
    InitImage(const int flags);
    ~InitImage();

    static constexpr int png = IMG_INIT_PNG;
};

}

#endif