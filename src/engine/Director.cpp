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
    current_scene_ = std::move(scene);
    current_scene_->create();
}

void Director::update()
{
    if (!is_playing()) {
        return;
    }

    current_scene_->update();
}

void Director::render()
{
    if (!is_playing()) {
        return;
    }

    current_scene_->render();
}

bool Director::is_playing()
{
    return static_cast<bool>(current_scene_);
}

const Director* const Director::get()
{
    static Director instance;
    return &instance;
}

}