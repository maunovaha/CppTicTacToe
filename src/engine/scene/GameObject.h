#pragma once

#include "../core/Component.h"
#include <memory>
#include <unordered_map>
#include <string>

namespace engine::scene {

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void onUpdate() {}
    virtual void onRender() const {}
    core::Component* addComponent(std::unique_ptr<core::Component> component);
    core::Component* getComponent(const std::string& componentName) const;
    bool hasComponent(const std::string& componentName) const;

    constexpr void setPosition(const int x, const int y)
    {
        this->x = x;
        this->y = y;
    }

    int x = 0;
    int y = 0;
    GameObject* parent = nullptr;
protected:
    // Ensures that all game objects are created via inheritance, e.g. "Player : public GameObject"
    GameObject(const int x, const int y) : x{x}, y{y} {}

    using ComponentKey   = std::string;
    using ComponentValue = std::unique_ptr<core::Component>;
    using ComponentMap   = std::unordered_map<ComponentKey, ComponentValue>;
    ComponentMap components_;
};

}