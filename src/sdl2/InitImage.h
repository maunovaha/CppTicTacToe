#ifndef SDL2_INIT_IMAGE_H
#define SDL2_INIT_IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace sdl2 {

class InitImage {
public:
    InitImage(const int flags);
    ~InitImage();

    static constexpr int png = IMG_INIT_PNG;
};

}

#endif