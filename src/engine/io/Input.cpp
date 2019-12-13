#include "Input.h"

namespace engine::io {

Input& Input::get()
{
    static Input instance;
    return instance;
}

const Mouse& Input::getMouse()
{
    return mouse_;
}

bool Input::isButtonPressed(const KeyCode buttonKeyCode)
{
    return mouse_.isButtonPressed(buttonKeyCode);
}

bool Input::isButtonReleased(const KeyCode buttonKeyCode)
{
    return mouse_.isButtonReleased(buttonKeyCode);
}

void Input::updateInputDevices(const SDL_Event& event)
{
    mouse_.handleInput(event);
}

void Input::resetInputDevices()
{
    mouse_.reset();
}

}