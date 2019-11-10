#ifndef GAME_H
#define GAME_H

#include "Gameboard.h"
#include "DifficultyLevel.h"

class Game {
public:
    Game(const DifficultyLevel difficulty_level = DifficultyLevel::easy);
private:
    void display_welcome_msg() const;
    void loop() const;
    void render() const;

    Gameboard gameboard_;
};

#endif