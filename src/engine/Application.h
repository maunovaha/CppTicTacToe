#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#include "../sdl2/Init.h"
#include "../sdl2/InitImage.h"
#include "../sdl2/Window.h"
#include "../sdl2/Renderer.h"
#include <string>

namespace engine {

class Application {
public:
    Application(const std::string& title, const int width, const int height);
private:
    void loop() const;

    sdl2::Init init_;
    sdl2::InitImage init_image_;
    sdl2::Window window_;
    sdl2::Renderer renderer_;
};

}

#endif