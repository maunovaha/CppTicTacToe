#ifndef APP_GAME_H
#define APP_GAME_H

#include "../engine/Application.h"
#include <string>

namespace app {

class Game : public engine::Application {
public:
    Game(const std::string& title, const int width, const int height);
};

}

#endif