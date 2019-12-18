#pragma once

#include "AppContext.h"
#include "../scene/Director.h"
#include "../gfx/TextureCache.h"
#include "../gfx/Window.h"
#include "../io/Input.h"
#include "sdl/SDL.h"
#include "sdl/SDLImage.h"
#include "sdl/SDLTTF.h"
#include <string>

namespace engine::core {

class Application {
protected:
    Application(const std::string& title, 
                const ui::Color& backgroundColor,
                const int width, 
                const int height, 
                const int x = gfx::Window::CENTERED, 
                const int y = gfx::Window::CENTERED);
    void run(std::unique_ptr<scene::Scene> startingScene);

    friend class AppContext;
private:
    void loop();
    bool processInput();
    void update();
    void render() const;

    sdl::SDL sdl_;
    sdl::SDLImage sdlImage_;
    sdl::SDLTTF sdlTTF_;

    gfx::Window window_;
    gfx::TextureCache textureCache_;

    io::Input input_;
    scene::Director director_;
};

}