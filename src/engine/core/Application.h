#pragma once

#include "AppContext.h"
#include "../scene/Director.h"
#include "TextureCache.h"
#include "Window.h"
#include "../io/Input.h"
#include "sdl/SDL.h"
#include "sdl/SDLImage.h"
#include "sdl/SDLTTF.h"
#include "sdl/SDLMixer.h"
#include <string>

namespace engine::core {

class Application {
protected:
    Application(const std::string& title, 
                const ui::Color& backgroundColor,
                const int width, 
                const int height, 
                const int x = Window::CENTERED, 
                const int y = Window::CENTERED);
    void run(std::unique_ptr<scene::Scene> startingScene);

    friend class AppContext;
private:
    void loop();
    void quit();
    void processInput();
    void update();
    void render() const;

    sdl::SDL sdl_;
    sdl::SDLImage sdlImage_;
    sdl::SDLTTF sdlTTF_;
    sdl::SDLMixer sdlMixer_;

    Window window_;
    TextureCache textureCache_;

    io::Input input_;
    scene::Director director_;
    
    bool running_ = false;
};

}