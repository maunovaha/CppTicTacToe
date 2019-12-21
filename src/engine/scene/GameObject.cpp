#include "GameObject.h"
#include "../world/Transform.h"

namespace engine::scene {

GameObject::GameObject(const math::Point& position)
{
    // All game objects have transform component by default (it's the same as in Unity)
    addComponent(std::make_unique<world::Transform>(position));
}

}