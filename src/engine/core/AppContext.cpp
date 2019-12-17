#include "Application.h"
#include <cassert>

namespace engine::core {

void AppContext::configure(const Application& app)
{
    instance_ = std::make_unique<AppContext>(app);
}

const gfx::Window& AppContext::getWindow()
{
    return get().app_.window_;
}

const gfx::Renderer& AppContext::getRenderer()
{
    return get().app_.window_.getRenderer();
}

const gfx::TextureCache& AppContext::getTextureCache()
{
    return get().app_.textureCache_;
}

const io::Input& AppContext::getInput()
{
    return get().app_.input_;
}

const scene::Director& AppContext::getDirector()
{
    return get().app_.director_;
}

const AppContext& AppContext::get()
{
    assert(instance_); // Ensures configure() is called before this method
    return *instance_.get();
}

}