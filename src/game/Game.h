#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "Grid.h"
#include "GameStatus.h"
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
    void display_game_over(const GameStatus& game_status) const;
    void render() const;
    GameStatus check_game_status() const;

    Grid grid_;
    std::vector<Player> players_;
    int current_player_index_ = 0;
};

}

#endif