#include "Game.h"

namespace game {

Game::Game(const std::string& title, const int width, const int height)
    : sdlx_{SDL_INIT_VIDEO}
    , window_{title, {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height}}
    , renderer_{window_, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC}
{
    loop();
}

void Game::loop() const
{
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        renderer_.clear();
        renderer_.present();
    }
}

}