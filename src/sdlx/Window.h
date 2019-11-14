#ifndef SDLX_WINDOW_H
#define SDLX_WINDOW_H

#include <SDL2/SDL.h>
#include <string>

namespace sdlx {

class Window {
public:
    Window(const std::string& title, const SDL_Rect& rect);
    ~Window();
    SDL_Window* get() const;
private:
    SDL_Window* window_ = nullptr;
};

}

#endif