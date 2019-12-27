#pragma once

#include "../../engine/scene/Scene.h"
#include "../../engine/math/Point.h"

namespace game::gameplay {

class GameplayScene : public engine::scene::Scene {
public:
    void onCreate() override;
private:
    void createGrid(const engine::math::Point& position);
};

}
