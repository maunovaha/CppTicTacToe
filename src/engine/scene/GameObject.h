#pragma once

#include "../core/Component.h"
#include "../math/Point.h"
#include <memory>
#include <unordered_map>
#include <string>
#include <typeindex>
#include <cassert>
#include <iostream>

namespace engine::scene {

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void onUpdate() {}
    virtual void onRender() const {}

    template<typename T>
    T& addComponent(std::unique_ptr<T> component)
    {
        assert(component);

        if (hasComponent<T>()) {
            std::cerr << "Warning: You tried to add same component twice." << std::endl;
            return getComponent<T>();
        }
        else {
            component->gameObject = this; // All components should know their GameObject
            return static_cast<T&>(
                *components_.emplace(toComponentKey<T>(), std::move(component)).first->second
            );
        }
    }

    template<typename T>
    T& getComponent() const
    {
        assert(hasComponent<T>());
        return static_cast<T&>(*components_.at(toComponentKey<T>()));
    }

    template<typename T>
    bool hasComponent() const
    {
        return components_.find(toComponentKey<T>()) != components_.end();
    }

    GameObject* parent = nullptr;
protected:
    // Ensures that all game objects are created via inheritance, e.g. "Player : public GameObject"
    GameObject(const math::Point& position);

    using ComponentKey   = std::type_index;
    using ComponentValue = std::unique_ptr<core::Component>;
    using ComponentMap   = std::unordered_map<ComponentKey, ComponentValue>;

    ComponentMap components_;
private:
    template<typename T>
    ComponentKey toComponentKey() const
    {
        return ComponentKey(typeid(T));
    }
};

}