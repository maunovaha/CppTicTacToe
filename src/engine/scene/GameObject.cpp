#include "GameObject.h"
#include "../ui/RectTransform.h"

namespace engine::ui {

class RectTransform; // Forward declaration

}

namespace engine::scene {

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

// Note: This is somewhat hacky way to get attached Transform component
// when we dont know whether Transform or RectTransform is added.
world::Transform& GameObject::getTransform() const
{
    if (hasComponent<ui::RectTransform>()) {
        return getComponent<ui::RectTransform>();
    }
    else {
        return getComponent<world::Transform>();
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