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
    director_.start(std::move(startingScene));
    loop();
}

void Application::quit()
{
    running_ = false;
}

void Application::loop()
{
    running_ = true;

    while (running_) {
        processInput();

        if (!running_) {
            break;
        }

        update();
        render();
    }
}

void Application::processInput()
{
    input_.reset();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running_ = false;
            break;
        }
        input_.update(event);
    }
}

void Application::update()
{
    director_.update();
}

void Application::render() const
{
    const Renderer& renderer = window_.getRenderer();

    renderer.clear();
    director_.render();
    renderer.present();
}

}