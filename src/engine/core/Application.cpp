#include "Application.h"

namespace engine::core {

Application::Application(const std::string& title,
                         const ui::Color& backgroundColor,
                         const int width,
                         const int height,
                         const int x,
                         const int y)
    : sdl_{sdl::SDL::VIDEO}
    , sdlImage_{sdl::SDLImage::PNG}
    , sdlTTF_{}
    , window_{title, backgroundColor, {x, y, width, height}}
    , textureCache_{}
    , input_{}
    , director_{}
{
    AppContext::configure(*this);
}

void Application::run(std::unique_ptr<scene::Scene> startingScene)
{
    director_.play(std::move(startingScene));
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

bool Application::processInput()
{
    input_.reset();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return true;
        }
        input_.update(event);
    }

    return false;
}

void Application::update()
{
    director_.update();
}

void Application::render() const
{
    director_.render();
}

}