#pragma once

namespace sdl2wrap {

class Rect : public SDL_Rect {
public:
    Rect(const int x, const int y, const int w, const int h)
        : SDL_Rect{x, y, w, h} {}
};

}