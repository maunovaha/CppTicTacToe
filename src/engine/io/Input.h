#pragma once

#include "Mouse.h"
#include "KeyCode.h"

namespace engine::io {

class Input {
public:
    const Mouse& getMouse() const;
    bool isButtonPressed(const KeyCode buttonKeyCode) const;
    bool isButtonReleased(const KeyCode buttonKeyCode) const;
    void update(const SDL_Event& event);
    void reset();
private:
    Mouse mouse_;
};

}