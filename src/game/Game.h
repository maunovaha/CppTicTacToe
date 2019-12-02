#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "../engine/Application.h"
#include <string>

namespace game {

class Game : public engine::Application {
public:
    Game(const std::string& title, const int width, const int height);
};

}

#endif