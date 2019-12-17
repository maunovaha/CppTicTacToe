#include "Director.h"
#include <utility>

namespace engine::scene {

void Director::play(std::unique_ptr<Scene> scene)
{
    currentScene_ = std::move(scene);
    currentScene_->onCreate();
}

void Director::update()
{
    if (!isPlaying()) {
        return;
    }

    currentScene_->preUpdate();
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