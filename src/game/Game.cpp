#include "Game.h"

namespace game {

Game::Game(const std::string& title, const int width, const int height)
    : engine::Application{title, width, height}
{
}

}