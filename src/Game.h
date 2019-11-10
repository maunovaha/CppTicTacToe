#ifndef GAME_H
#define GAME_H

#include "Gameboard.h"
#include "DifficultyLevel.h"
#include "Player.h"
#include <vector>

class Game {
public:
    Game(const DifficultyLevel difficulty_level = DifficultyLevel::easy);
private:
    void display_welcome_msg() const;
    void loop();
    void render() const;
    void update();
    void change_turn();

    Gameboard gameboard_;
    std::vector<Player> players_;
    int current_player_index_ = 0;
};

#endif