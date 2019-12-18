#include "Scene.h"
#include <utility>
#include "../Core/AppContext.h"

namespace engine::scene {

void Scene::render() const
{
    for (const auto& gameObject : gameObjects_) {
        gameObject->onRender({0, 0});
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