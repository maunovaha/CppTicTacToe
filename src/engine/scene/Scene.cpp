#include "Scene.h"

namespace engine::scene {

void Scene::render() const
{
    for (const auto& gameObject : gameObjects_) {
        gameObject->onRender();
    }
}

void Scene::update()
{
    for (const auto& gameObject : gameObjects_) {
        gameObject->onUpdate();
    }
}

void Scene::addChild(std::shared_ptr<GameObject> gameObject)
{
    gameObjects_.emplace_back(std::move(gameObject));
}

}