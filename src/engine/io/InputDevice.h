#pragma once

#if defined(_WIN32)
    #include <SDL.h>
#else
    #include <SDL2/SDL.h>
#endif

namespace engine::io {

class InputDevice {
public:
    virtual void handleInput(const SDL_Event& event) = 0;
    virtual void reset() = 0;
    virtual ~InputDevice() = default;
protected:
    enum class ButtonState {
        Idle = 0, Pressed, Released
    };
};

}