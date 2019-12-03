#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#include "Scene.h"
#include "../sdl2wrap/SDL.h"
#include "../sdl2wrap/SDLImage.h"
#include "../sdl2wrap/Window.h"
#include "../sdl2wrap/Renderer.h"
#include <string>

namespace engine {

class Application {
public:
    Application(const std::string& title, const int width, const int height);
protected:
    void start(std::unique_ptr<Scene> starting_scene) const;
private:
    void loop() const;
    bool process_input() const;
    void update() const;
    void render() const;

    sdl2wrap::SDL sdl_;
    sdl2wrap::SDLImage sdl_image_;
    sdl2wrap::Window window_;
    sdl2wrap::Renderer renderer_;
};

}

#endif