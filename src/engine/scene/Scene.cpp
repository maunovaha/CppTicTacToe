#include "Scene.h"
#include <utility>

namespace engine::scene {

void Scene::render(const gfx::Window& window) const
{
    for (const auto& gameObject : gameObjects_) {
        gameObject->render(window.getRenderer());
    }
}

void Scene::addChild(std::shared_ptr<GameObject> gameObject)
{
    gameObjects_.emplace_back(std::move(gameObject));
}

}