#pragma once

#include "../engine/core/Application.h"
#include <string>

namespace game {

class AppDelegate : public engine::core::Application {
public:
    AppDelegate(const std::string& title, const int width, const int height);
};

}