#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "../sdlx/Sdlx.h"
#include "../sdlx/Window.h"
#include "../sdlx/Renderer.h"
#include <string>

namespace game {

class Game {
public:
    Game(const std::string& title, const int width, const int height);
private:
    void loop() const;

    sdlx::Sdlx sdlx_;
    sdlx::Window window_;
    sdlx::Renderer renderer_;
};

}

#endif