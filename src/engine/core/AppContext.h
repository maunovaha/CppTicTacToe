#pragma once

#include "../scene/Director.h"
#include "TextureCache.h"
#include "Window.h"
#include "../io/Input.h"
#include <memory>

namespace engine::core {

class Application; // Forward declaration
class AppContext {
public:
    AppContext(Application& app) : app_{app} {}
    AppContext(const AppContext&) = delete;
    void operator=(const AppContext&) = delete;
    static void configure(Application& app);
    static const Window& getWindow();
    static const Renderer& getRenderer();
    static TextureCache& getTextureCache();
    static const io::Input& getInput();
    static scene::Director& getDirector();
    static void quit();
private:
    static const AppContext& get();

    /*const*/ Application& app_;
    static inline std::unique_ptr<AppContext> instance_;
};

}