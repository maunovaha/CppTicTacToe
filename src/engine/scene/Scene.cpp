#include "Scene.h"

namespace engine::scene {

void Scene::onExit()
{
    // Tagged game objects are stored to static map inside GameObject, for this reason,
    // we need to manually reset the state of the GameObject before we enter to a new scene. 
    // Otherwise, tagged game objects persists between scenes; Hence, it is not something
    // we want to do atm.
    GameObject::removeTaggedGameObjects();
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

GameObject* Scene::getChild(const unsigned int index) const
{
    return root_->getChild(index);
}

} 