#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif
#include <string>
#include <memory>

namespace sdl2wrap {

class Window {
public:
    Window(const std::string& title, const SDL_Rect& rect);
    SDL_Window* get() const;

    static constexpr Uint32 centered = SDL_WINDOWPOS_CENTERED;
private:
    struct DestroyWindow {
        void operator()(SDL_Window* window) const
        {
            SDL_DestroyWindow(window);
        }
    };

    using UniqueWindowPtr = std::unique_ptr<SDL_Window, DestroyWindow>;

    UniqueWindowPtr window_;
};

}
