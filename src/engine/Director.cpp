#include "Director.h"
#include <utility>

namespace engine {

void Director::play(std::unique_ptr<Scene> scene)
{
    current_scene_ = std::move(scene);
    current_scene_->create();
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