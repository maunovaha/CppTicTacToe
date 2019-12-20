#pragma once

#include "../core/Component.h"
#include "../math/Point.h"
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

    GameObject* parent = nullptr;
protected:
    // Ensures that all game objects are created via inheritance, e.g. "Player : public GameObject"
    GameObject(const math::Point& position);

    using ComponentKey   = std::string;
    using ComponentValue = std::unique_ptr<core::Component>;
    using ComponentMap   = std::unordered_map<ComponentKey, ComponentValue>;
    ComponentMap components_;
};

}