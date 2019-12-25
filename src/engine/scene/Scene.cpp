#include "Scene.h"

namespace engine::scene {

void Scene::update()
{
    root_->onUpdate();
}

void Scene::render() const
{
    root_->onRender();
}

void Scene::addChild(std::unique_ptr<GameObject> child)
{
    root_->addChild(std::move(child));
}

} 