#pragma once

#include "Player.h"
#include "../../engine/scene/Scene.h"
#include "../../engine/math/Point.h"
#include <vector>

namespace game::gameplay {

class GameplayScene : public engine::scene::Scene {
public:
    void onCreate() override;
private:
    void createGrid(const engine::math::Point& position, const int size);
    std::vector<Player> createPlayers();
    void createGameLogic(std::vector<Player> players);
};

}
