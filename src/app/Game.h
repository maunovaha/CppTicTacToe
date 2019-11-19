#ifndef APP_GAME_H
#define APP_GAME_H

#include "../sdlx/Sdlx.h"
#include "../sdlx/Window.h"
#include "../sdlx/Renderer.h"
#include <string>

namespace app {

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