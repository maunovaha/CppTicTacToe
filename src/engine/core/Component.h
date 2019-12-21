#pragma once

#include <string>

namespace engine::scene {

class GameObject; // Forward declaration

}

namespace engine::core {

class Component {
public:
    virtual ~Component() = default;
    virtual void onUpdate() {}
    virtual void onRender() const {}

    scene::GameObject* gameObject = nullptr;
protected:
    // Ensures that all components are created via inheritance, e.g. "Transform : public Component"
    Component() = default;
};

}
