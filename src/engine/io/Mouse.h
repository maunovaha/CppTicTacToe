#pragma once

#include "InputDevice.h"
#include "KeyCode.h"
#include "../math/Point.h"
#include <unordered_map>

namespace engine::io {

class Mouse : public InputDevice {
public:
    int getX() const;
    int getY() const;
    math::Point getPosition() const;
    bool isButtonPressed(const KeyCode buttonKeyCode) const;
    bool isButtonReleased(const KeyCode buttonKeyCode) const;
    void handleInput(const SDL_Event& event) override;
    void reset() override;
private:
    void handleMotion(const SDL_MouseButtonEvent& buttonEvent);
    void handleButtonStateChange(const Uint32 eventType, const SDL_MouseButtonEvent& buttonEvent);
    bool isKnownButton(const KeyCode& buttonKeyCode) const;

    int x_ = 0;
    int y_ = 0;

    static inline std::unordered_map<KeyCode, ButtonState> buttons_ = {
        {KeyCode::MouseLeft, ButtonState::Idle}
    };
};

}