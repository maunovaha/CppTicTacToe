#include "Input.h"

namespace engine::io {

const Mouse& Input::getMouse() const
{
    return mouse_;
}

bool Input::isButtonPressed(const KeyCode buttonKeyCode) const
{
    return mouse_.isButtonPressed(buttonKeyCode);
}

bool Input::isButtonReleased(const KeyCode buttonKeyCode) const
{
    return mouse_.isButtonReleased(buttonKeyCode);
}

void Input::update(const SDL_Event& event)
{
    mouse_.handleInput(event);
}

void Input::reset()
{
    mouse_.reset();
}

}