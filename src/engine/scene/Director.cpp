#include "Director.h"
#include <cassert>
#include <iostream>

namespace engine::scene {

void Director::start(std::unique_ptr<Scene> startingScene)
{
    assert(!isStarted());

    currentScene_ = std::move(startingScene);
    currentScene_->onCreate();
}

void Director::play(std::unique_ptr<Scene> scene)
{
    assert(isStarted());

    if (isLoading()) {
        std::cerr << "Warning: Already loading another scene!" << std::endl;
        return;
    }

    nextScene_ = std::move(scene);
}

void Director::update()
{
    assert(isStarted());

    if (isLoading()) {
        currentScene_->onExit();
        currentScene_ = std::move(nextScene_);
        currentScene_->onCreate();
    }

    currentScene_->update();
}

void Director::render() const
{
    assert(isStarted());

    currentScene_->render();
}

bool Director::isStarted() const
{
    return static_cast<bool>(currentScene_);
}

bool Director::isLoading() const
{
    return static_cast<bool>(nextScene_);
}

}