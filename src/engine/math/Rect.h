#pragma once

namespace engine::math {

class Rect : public SDL_Rect { // REFACTOR: Do not inherit, use composition
public:
    Rect(const int x, const int y, const int w, const int h)
        : SDL_Rect{x, y, w, h} {}
};

}