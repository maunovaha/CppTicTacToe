#ifndef ENGINE_APPLICATION_H
#define ENGINE_APPLICATION_H

#include "../sdlx/Sdlx.h"
#include "../sdlx/Window.h"
#include "../sdlx/Renderer.h"
#include <string>

namespace engine {

class Application {
public:
    Application(const std::string& title, const int width, const int height);
private:
    void loop() const;

    sdlx::Sdlx sdlx_;
    sdlx::Window window_;
    sdlx::Renderer renderer_;
};

}

#endif