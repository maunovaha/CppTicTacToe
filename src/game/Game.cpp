#include "Game.h"
#include "Chip.h"
#include <iostream>
#include <memory>

namespace game {

Game::Game(const DifficultyLevel difficulty_level) 
    : grid_{static_cast<int>(difficulty_level)}
    , players_{{"Player (X)", Chip::x()}, {"Player (O)", Chip::o()}}
{
    display_welcome_msg();
    loop();
}

void Game::loop()
{
    render();
    update();
    change_turn();
    loop();
}

void Game::update()
{
    players_.at(current_player_index_).update(grid_);
}

void Game::change_turn()
{
    ++current_player_index_;

    if (current_player_index_ >= players_.size()) {
        current_player_index_ = 0;
    }
}

void Game::display_welcome_msg() const
{
    std::cout << "\n============================"
              << "\nWelcome to play Tic-tac-toe!" 
              << "\n============================" << std::endl;
}

void Game::render() const
{
    grid_.render();
}

}