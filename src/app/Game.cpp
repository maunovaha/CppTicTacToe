#include "Game.h"

namespace app {

Game::Game(const std::string& title, const int width, const int height)
    : engine::Application{title, width, height}
{
}

}