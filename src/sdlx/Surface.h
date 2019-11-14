#ifndef SDLX_SURFACE_H
#define SDLX_SURFACE_H

#include <SDL2/SDL.h>
#include <string>

namespace sdlx {

class Surface {
public:
    Surface(const std::string& image_path);
    ~Surface();
    int width() const;
    int height() const;
    SDL_Surface* get() const;
private:
    SDL_Surface* surface_ = nullptr;
};

}

#endif