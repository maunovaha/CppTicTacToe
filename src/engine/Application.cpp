#include "Application.h"

namespace engine {

void Application::run(std::unique_ptr<Scene> startingScene)
{
    director_.play(std::move(startingScene), window_);
    loop();
}

void Application::loop()
{
    for (;;) {
        const bool exitRequest = processInput();

        if (exitRequest) {
            break;
        }

        update();
        render();
    }
}

bool Application::processInput() const
{
    SDL_Event event;                  // REFACTOR: Implement sdl2wrap::Event?
    while (SDL_PollEvent(&event)) {   // REFACTOR: Implement sdl2wrap::Event::poll()?
        if (event.type == SDL_QUIT) { // REFACTOR: Implement sdl2wrap::SDL::quit?
            return true;
        }
        // TODO: Add later logic for processing keyboard/mouse input
    }

    return false;
}

void Application::update()
{
    director_.update();
}

void Application::render() const
{
    window_.clear();
    director_.render(window_);
    window_.present();
}

}