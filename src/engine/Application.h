#pragma once

#include "Window.h"
#include "Director.h"
#include "../sdl2wrap/SDL.h"
#include "../sdl2wrap/SDLImage.h"
#include <string>

namespace engine {

class Application {
protected:
    Application(const std::string& title, 
                const int width, 
                const int height, 
                const int x = Window::CENTERED, 
                const int y = Window::CENTERED)
        : sdl_{sdl2wrap::SDL::VIDEO}
        , sdlImage_{sdl2wrap::SDLImage::PNG}
        , window_{title, {x, y, width, height}}
        , director_{} {}
    void run(std::unique_ptr<Scene> startingScene);
private:
    void loop();
    bool processInput() const;
    void update();
    void render() const;

    sdl2wrap::SDL sdl_;
    sdl2wrap::SDLImage sdlImage_;

    Window window_;
    Director director_;
};

}