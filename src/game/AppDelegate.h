#ifndef GAME_APP_DELEGATE_H
#define GAME_APP_DELEGATE_H

#include "../engine/Application.h"
#include <string>

namespace game {

class AppDelegate : public engine::Application {
public:
    AppDelegate(const std::string& title, const int width, const int height);
};

}

#endif