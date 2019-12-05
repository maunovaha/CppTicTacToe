#include "Director.h"
#include <utility>

namespace engine {

void Director::play(std::unique_ptr<Scene> scene)
{
    currentScene_ = std::move(scene);
    currentScene_->create();
}

void Director::update()
{
    if (!isPlaying()) {
        return;
    }

    currentScene_->update();
}

void Director::render() const
{
    if (!isPlaying()) {
        return;
    }

    currentScene_->render();
}

bool Director::isPlaying() const
{
    return static_cast<bool>(currentScene_);
}

}