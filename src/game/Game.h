#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "DifficultyLevel.h"
#include "Player.h"
#include <vector>

namespace game {

class Game {
public:
    Game(const DifficultyLevel difficulty_level = DifficultyLevel::easy);
private:
    void loop();
    void update();
    void change_turn();
    void display_welcome_msg() const;
    void render() const;

    Grid grid_;
    std::vector<Player> players_;
    int current_player_index_ = 0;
};

}

#endif