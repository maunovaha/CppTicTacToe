#include "Director.h"
#include <utility>

namespace engine {

void Director::play(std::unique_ptr<Scene> scene)
{
    // POSSIBLE BUG: Atm. nothing stops us calling this method before the Application::start(), 
    // which would cause a bug, because we would never enter to the actual Application::loop :(
    //
    // This should be fixed either here by checking if the Application is ready (via assert?)
    // or using some other approach for warning the developers.
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

void Director::render()
{
    if (!isPlaying()) {
        return;
    }

    currentScene_->render();
}

bool Director::isPlaying()
{
    return static_cast<bool>(currentScene_);
}

const Director* const Director::get()
{
    static Director instance;
    return &instance;
}

}