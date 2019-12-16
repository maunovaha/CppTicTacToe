#pragma once

#include "../scene/Director.h"
#include "../gfx/TextureCache.h"
#include "../gfx/Window.h"
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
                const int y = gfx::Window::CENTERED)
        : sdl_{sdl::SDL::VIDEO}
        , sdlImage_{sdl::SDLImage::PNG}
        , sdlTTF_{}
        , window_{title, backgroundColor, {x, y, width, height}}
        , textureCache_{} 
        , director_{} {}
    void run(std::unique_ptr<scene::Scene> startingScene);
private:
    void loop();
    void update();
    void render() const;
    bool processInput() const;

    sdl::SDL sdl_;
    sdl::SDLImage sdlImage_;
    sdl::SDLTTF sdlTTF_;

    gfx::Window window_;
    gfx::TextureCache textureCache_;

    scene::Director director_;
};

}