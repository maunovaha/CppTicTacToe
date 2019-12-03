#include "Application.h"
#include "Director.h"

namespace engine {

Application::Application(const std::string& title, const int width, const int height)
    : sdl_{sdl2wrap::SDL::VIDEO}
    , sdl_image_{sdl2wrap::SDLImage::PNG}
    , window_{title, {sdl2wrap::Window::CENTERED, sdl2wrap::Window::CENTERED, width, height}}
    , renderer_{window_, {0xFF, 0xFF, 0xFF, 0xFF}, sdl2wrap::Renderer::ACCELERATED | sdl2wrap::Renderer::PRESENTVSYNC}
{
}

void Application::start(std::unique_ptr<Scene> starting_scene) const
{
    engine::Director::get()->play(std::move(starting_scene));
    loop();
}

void Application::loop() const
{
    for (;;) {
        const bool exit_request = process_input();

        if (exit_request) {
            break;
        }

        update();
        render();
    }
}

bool Application::process_input() const
{
    SDL_Event event;                  // REFACTOR: Implement sdl2wrap::Event (?)
    while (SDL_PollEvent(&event)) {   // REFACTOR: Implement sdl2wrap::Event::poll(...) (?)
        if (event.type == SDL_QUIT) { // REFACTOR: Implement sdl2wrap::SDL::quit (?)
            return true;
        }
        // TODO: Add later logic for processing keyboard/mouse input
    }

    return false;
}

void Application::update() const
{
    Director::get()->update();
}

void Application::render() const
{
    renderer_.clear();
    Director::get()->render();
    renderer_.present();
}

}