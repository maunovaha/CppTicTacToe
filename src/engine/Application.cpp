#include "Application.h"

namespace engine {

Application::Application(const std::string& title, const int width, const int height)
    : init_{sdl2::Init::video}
    , init_image_{sdl2::InitImage::png}
    , window_{title, {sdl2::Window::centered, sdl2::Window::centered, width, height}}
    , renderer_{window_, {0xFF, 0xFF, 0xFF, 0xFF}, sdl2::Renderer::accelerated | sdl2::Renderer::presentvsync}
{
    loop();
}

void Application::loop() const
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