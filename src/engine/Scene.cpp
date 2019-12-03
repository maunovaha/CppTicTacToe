#include "Scene.h"
#include <utility>

namespace engine {

void Scene::render() const
{
    for (const auto& gameObject : gameObjects_) {
        gameObject->render();
    }
}

void Scene::addChild(std::shared_ptr<GameObject> gameObject)
{
    gameObjects_.emplace_back(std::move(gameObject));
}

}
