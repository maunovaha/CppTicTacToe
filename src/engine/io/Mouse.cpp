#include "Mouse.h"
#include <cassert>

namespace engine::io {

int Mouse::getX() const
{
    return x_;
}

int Mouse::getY() const
{
    return y_;
}

bool Mouse::isButtonPressed(const KeyCode buttonKeyCode) const
{
    if (!isKnownButton(buttonKeyCode)) {
        return false;
    }

    return buttons_.at(buttonKeyCode) == ButtonState::Pressed;
}

bool Mouse::isButtonReleased(const KeyCode buttonKeyCode) const
{
    if (!isKnownButton(buttonKeyCode)) {
        return false;
    }

    return buttons_.at(buttonKeyCode) == ButtonState::Released;
}

void Mouse::handleInput(const SDL_Event& event)
{
    switch (event.type) {
    case SDL_MOUSEMOTION:
        handleMotion(event.button);
        break;
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
        handleButtonStateChange(event.type, event.button);
        break;
    }
}

void Mouse::reset()
{
    for (auto& button : buttons_) {
        button.second = ButtonState::Idle;
    }
}

void Mouse::handleMotion(const SDL_MouseButtonEvent& buttonEvent)
{
    x_ = buttonEvent.x;
    y_ = buttonEvent.y;
}

void Mouse::handleButtonStateChange(const Uint32 eventType, const SDL_MouseButtonEvent& buttonEvent)
{
    assert(eventType == SDL_MOUSEBUTTONDOWN || eventType == SDL_MOUSEBUTTONUP);

    const KeyCode buttonKeyCode = static_cast<KeyCode>(buttonEvent.button);

    if (!isKnownButton(buttonKeyCode)) {
        // Note: Enable this warning to debug unhandled mouse buttons.
        // std::cerr << "Warning: We received button press for unhandled mouse keycode, code: "
        //           << static_cast<int>(buttonEvent.button) << std::endl;
        return;
    }

    // Note: This line might cause a bug if we do not assert at the beginning of the function,
    // because we work under an assumption that only two type of events are coming in to the 
    // function: SDL_MOUSEBUTTONDOWN or SDL_MOUSEBUTTONUP (if / else)
    const ButtonState buttonState = eventType == SDL_MOUSEBUTTONDOWN ? ButtonState::Pressed
                                                                     : ButtonState::Released;
    buttons_.at(buttonKeyCode) = buttonState;
}

bool Mouse::isKnownButton(const KeyCode& buttonKeyCode) const
{
    return buttons_.find(buttonKeyCode) != buttons_.end();
}

}