#include "GameObject.h"
#include "../world/Transform.h"

namespace engine::scene {

GameObject::GameObject(const math::Point& localPosition)
{
    // Every GameObject has Transform component by default (mimics Unity).
    addComponent(std::make_unique<world::Transform>(localPosition));
}

GameObject::GameObject(const std::string& tag, const math::Point& localPosition) 
    : GameObject{localPosition}
{
    storeWithTag(tag);
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

void GameObject::setParent(GameObject& parent)
{
    parent_ = &parent;
}

GameObject* GameObject::getParent() const
{
    return parent_;
}

void GameObject::addChild(std::unique_ptr<GameObject> child)
{
    // TODO: assert(child != this || child.getParent()); ?

    child.get()->setParent(*this);
    children_.emplace_back(std::move(child));
}

GameObject* GameObject::getChild(const unsigned int index) const
{
    if (hasChildAt(index)) {
        return children_.at(index).get();
    }
    return nullptr;
}

bool GameObject::hasChildAt(const unsigned int index) const
{
    return (index + 1) <= children_.size();
}

int GameObject::getChildCount() const
{
    return children_.size();
}

void GameObject::storeWithTag(const std::string& tag)
{
    assert(!isTagged(tag));
    taggedGameObjects_.emplace(tag, this);
}

bool GameObject::isTagged(const std::string& tag)
{
    return taggedGameObjects_.find(tag) != taggedGameObjects_.end();
}

}