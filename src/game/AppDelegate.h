#pragma once

#include "../engine/core/Application.h"
#include "../engine/ui/Color.h"
#include <string>

namespace game {

class AppDelegate : public engine::core::Application {
public:
    AppDelegate(const std::string& title, 
                const engine::ui::Color& backgroundColor, 
                const int width, 
                const int height);
};

}