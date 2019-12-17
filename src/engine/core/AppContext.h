#pragma once

#include "Application.h"
#include "../scene/Director.h"
#include "../gfx/TextureCache.h"
#include "../gfx/Window.h"
#include "../io/Input.h"
#include <memory>

namespace engine::core {

class Application; // Forward declaration
class AppContext {
public:
    AppContext(const Application& app) : app_{app} {}
    AppContext(const AppContext&) = delete;
    void operator=(const AppContext&) = delete;
    static void configure(const Application& app);
    static const gfx::Window& getWindow();
    static const gfx::Renderer& getRenderer();
    static const gfx::TextureCache& getTextureCache();
    static const io::Input& getInput();
    static const scene::Director& getDirector();
private:
    static const AppContext& get();

    const Application& app_;
    static inline std::unique_ptr<AppContext> instance_;
};

}