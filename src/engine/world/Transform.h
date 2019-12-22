#pragma once

#include "../scene/GameObject.h"
#include "../core/Component.h"
#include "../math/Rect.h"
#include "../math/Point.h"

namespace engine::world {

class Transform : public core::Component {
public:
    Transform(const math::Point& localPosition) : localPosition{localPosition} {}

    math::Point getWorldPosition() const
    {
        math::Point worldPosition = localPosition;
        const scene::GameObject* parent = gameObject->getParent();

        if (parent) {
            worldPosition += parent->getTransform().getWorldPosition();
        }

        return worldPosition;
    }

    math::Point localPosition;
};

}