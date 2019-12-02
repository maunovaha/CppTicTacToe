#include "Scene.h"
#include <utility>

namespace engine {

void Scene::render() const
{
    for (const auto& game_object : game_objects_) {
        game_object->render();
    }
}

void Scene::add_child(std::shared_ptr<GameObject> game_object)
{
    game_objects_.emplace_back(std::move(game_object));
}

}
