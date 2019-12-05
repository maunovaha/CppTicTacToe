#include "Director.h"
#include <utility>

namespace engine {

void Director::play(std::unique_ptr<Scene> scene, const Window& window)
{
    currentScene_ = std::move(scene);
    currentScene_->create(window);
}

void Director::update()
{
    if (!isPlaying()) {
        return;
    }

    currentScene_->update();
}

void Director::render(const Window& window) const
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