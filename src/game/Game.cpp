#include "Game.h"
#include "Chip.h"
#include <iostream>
#include <cassert>

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

    GameStatus game_status = check_game_status();

    if (game_status.is_game_over()) {
        return display_game_over(game_status);
    }

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

void Game::display_game_over(const GameStatus& game_status) const
{
    assert(game_status.is_game_over());

    render(); // Renders the placement of the final chip

    if (game_status.is_draw()) {
        std::cout << "*** Game over, it was a draw!" << std::endl;
    }
    else {
        std::cout << "*** Game over, " << *game_status.get_winner() << " won!" << std::endl;
    }
}

void Game::render() const
{
    grid_.render();
}

GameStatus Game::check_game_status() const
{
    return {grid_, players_.at(current_player_index_)};
}

}