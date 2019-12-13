#pragma once

#include "Mouse.h"
#include "KeyCode.h"

namespace engine::io {

class Input {
public:
    Input(const Input&) = delete;
    void operator=(const Input&) = delete;
    static Input& get();
    static const Mouse& getMouse();
    static bool isButtonPressed(const KeyCode buttonKeyCode);
    static bool isButtonReleased(const KeyCode buttonKeyCode);
    static void updateInputDevices(const SDL_Event& event);
    static void resetInputDevices();
private:
    Input() = default;

    static inline Mouse mouse_;
};

}