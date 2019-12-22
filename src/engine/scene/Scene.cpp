#include "Scene.h"
#include "../world/Transform.h"
#include "../math/Point.h"

namespace engine::scene {

Scene::Scene()
{
    // Every scene has a "root" game object by default; This makes calling render/update easier.
    root_ = std::make_unique<GameObject>();
    root_->addComponent(std::make_unique<world::Transform>(math::Point{0, 0}));
}

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