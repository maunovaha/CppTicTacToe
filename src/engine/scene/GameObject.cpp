#include "GameObject.h"
#include "../world/Transform.h"

namespace engine::scene {

GameObject::GameObject(const math::Point& localPosition)
{
    // Every GameObject has Transform component by default (mimics Unity).
    addComponent(std::make_unique<world::Transform>(localPosition));
}

void GameObject::onUpdate()
{
    for (const auto& component : components_) {
        component.second->onUpdate();
    }

    for (const auto& child : children_) {
        child->onUpdate();
    }
}

void GameObject::onRender() const
{
    for (const auto& component : components_) {
        component.second->onRender();
    }

    for (const auto& child : children_) {
        child->onRender();
    }
}

void GameObject::addChild(std::unique_ptr<GameObject> child)
{
    // TODO: assert(child != this || child.getParent()); ?

    child.get()->setParent(*this);
    children_.emplace_back(std::move(child));
}

void GameObject::setParent(GameObject& parent)
{
    parent_ = &parent;
}

GameObject* GameObject::getParent() const
{
    return parent_;
}

}