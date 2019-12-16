#include "Scene.h"
#include <utility>

namespace engine::scene {

void Scene::render(const gfx::Window& window) const
{
    for (const auto& gameObject : gameObjects_) {
        gameObject->onRender(window.getRenderer(), {0, 0});
    }
}

void Scene::preUpdate()
{
    onUpdate();

    for (const auto& gameObject : gameObjects_) {
        gameObject->onUpdate();
    }
}

void Scene::addChild(std::shared_ptr<GameObject> gameObject)
{
    gameObjects_.emplace_back(std::move(gameObject));
}

}