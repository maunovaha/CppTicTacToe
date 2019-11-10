#include <string>
#include <iostream>
#include "Game.h"

Game::Game(const DifficultyLevel difficulty_level) : gameboard_{static_cast<int>(difficulty_level)}
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

void Game::loop() const
{
    render();
}

void Game::render() const
{
    gameboard_.render();
}