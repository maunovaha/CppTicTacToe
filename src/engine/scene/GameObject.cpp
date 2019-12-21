#include "GameObject.h"

namespace engine::scene {

void GameObject::onUpdate()
{
    for (const auto& component : components_) {
        component.second->onUpdate();
    }
}

void GameObject::onRender() const
{
    for (const auto& component : components_) {
        component.second->onRender();
    }
}

}