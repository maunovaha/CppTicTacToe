#include "Application.h"
#include "../io/Input.h"

namespace engine::core {

void Application::run(std::unique_ptr<scene::Scene> startingScene)
{
    director_.play(std::move(startingScene), window_, textureCache_);
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
    io::Input::get().resetInputDevices();

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true;
        }
        io::Input::get().updateInputDevices(event);
    }

    return false;
}

void Application::update()
{
    director_.update();
}

void Application::render() const
{
    window_.getRenderer().clear();
    director_.render(window_);
    window_.getRenderer().present();
}

}