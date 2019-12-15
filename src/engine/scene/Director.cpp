#include "Director.h"
#include <utility>

namespace engine::scene {

void Director::play(std::unique_ptr<Scene> scene, const gfx::Window& window, gfx::TextureCache& textureCache)
{
    currentScene_ = std::move(scene);
    currentScene_->create(window, textureCache);
}

void Director::update()
{
    if (!isPlaying()) {
        return;
    }

    currentScene_->update();
}

void Director::render(const gfx::Window& window) const
{
    if (!isPlaying()) {
        return;
    }

    currentScene_->render(window);
}

bool Director::isPlaying() const
{
    return static_cast<bool>(currentScene_);
}

}