#include "GameObject.h"
#include <cassert>
#include <iostream>

namespace engine::scene {

core::Component* GameObject::addComponent(std::unique_ptr<core::Component> component)
{
    assert(component);

    if (hasComponent(component->name)) {
        std::cerr << "Warning: You tried to added component (" << component->name << ") twice.\n";
        return getComponent(component->name);
    }
    else {
        component->gameObject = this; // Components should know their host

        return components_.emplace(component->name, std::move(component)).first->second.get();
    }
}

core::Component* GameObject::getComponent(const std::string& componentName) const
{
    assert(hasComponent(componentName));

    return components_.at(componentName).get();
}

bool GameObject::hasComponent(const std::string& componentName) const
{
    return components_.find(componentName) != components_.end();
}

}