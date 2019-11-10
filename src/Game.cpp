#include <string>
#include <iostream>
#include "Game.h"

Game::Game(const DifficultyLevel difficulty_level) 
    : gameboard_{static_cast<int>(difficulty_level)}
    , players_{{"Player (X)", 'X'}, {"Player (O)", 'O'}}
{
    display_welcome_msg();
    loop();
}

void Game::display_welcome_msg() const
{
    std::cout << "\n============================"
              << "\nWelcome to play Tic Tac Toe!" 
              << "\n============================" << std::endl;
}

void Game::loop()
{
    render();
    update();
    change_turn();
    loop();
}

void Game::render() const
{
    gameboard_.render();
}

void Game::update()
{
    players_.at(current_player_index_).update(gameboard_);
}

void Game::change_turn()
{
    ++current_player_index_;

    if (current_player_index_ >= players_.size()) {
        current_player_index_ = 0;
    }
}

