#include "Application.h"

namespace engine {

Application::Application(const std::string& title, const int width, const int height)
    : init_{SDL2wrap::Init::video}
    , init_image_{SDL2wrap::InitImage::png}
    , window_{title, {SDL2wrap::Window::centered, SDL2wrap::Window::centered, width, height}}
    , renderer_{window_, {0xFF, 0xFF, 0xFF, 0xFF}, SDL2wrap::Renderer::accelerated | SDL2wrap::Renderer::presentvsync}
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