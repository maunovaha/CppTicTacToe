#include "GameStatus.h"
#include "../util/StringUtil.h"

namespace game {

GameStatus::GameStatus(const Grid& grid, const Player& current_player) 
    : game_info_{check_game_over(grid, current_player)}
{
}

GameStatus::GameInfo GameStatus::check_game_over(const Grid& grid, const Player& current_player) const
{
    // This is just a reminder to fix the code in case the grid size changes, because the current
    // `is_winning_match(...)` is hard-coded(!)
    assert(grid.size() == 3);

    // E.g. "XXX" for Player (X)
    const std::string winning_pattern = util::StringUtil::repeat(current_player.get_chip(), winning_chip_count_);

    if (grid.is_full()) {
        return {false}; // Draw, no one won!
    }
    else if (is_winning_match(winning_pattern, grid)) {
        return {false, std::make_shared<Player>(current_player)};
    }

    return {true}; // Game is still ongoing
}

bool GameStatus::is_game_over() const
{
    return !game_info_.running;
}

bool GameStatus::is_draw() const
{
    return !game_info_.running && !game_info_.winner;
}

const std::shared_ptr<Player>& GameStatus::get_winner() const
{
    return game_info_.winner;
}

bool GameStatus::is_winning_match(const std::string& pattern, const Grid& grid) const
{
    return is_horizontal_match(pattern, grid)
        || is_vertical_match(pattern, grid)
        || is_diagonal_match_from_left_to_right(pattern, grid)
        || is_diagonal_match_from_right_to_left(pattern, grid);
}

// Note: Contains hard-coding, so remember to fix this when switching to larger grids.
bool GameStatus::is_horizontal_match(const std::string& pattern, const Grid& grid) const
{
    for (int row = 0; row < grid.size(); ++row) {
        const std::string chip1 = grid.get_slot(row, 0);
        const std::string chip2 = grid.get_slot(row, 1);
        const std::string chip3 = grid.get_slot(row, 2);
        const std::string horizontal_pattern = chip1 + chip2 + chip3;

        if (horizontal_pattern == pattern) {
            return true;
        }
    }

    return false;
}

// Note: Contains hard-coding, so remember to fix this when switching to larger grids.
bool GameStatus::is_vertical_match(const std::string& pattern, const Grid& grid) const
{
    for (int column = 0; column < grid.size(); ++column) {
        const std::string chip1 = grid.get_slot(0, column);
        const std::string chip2 = grid.get_slot(1, column);
        const std::string chip3 = grid.get_slot(2, column);
        const std::string vertical_pattern = chip1 + chip2 + chip3;

        if (vertical_pattern == pattern) {
            return true;
        }
    }

    return false;
}

// Note: Contains hard-coding, so remember to fix this when switching to larger grids.
bool GameStatus::is_diagonal_match_from_left_to_right(const std::string& pattern, const Grid& grid) const
{
    const int row = 0;
    const int column = 0;

    const std::string chip1 = grid.get_slot(row, column);
    const std::string chip2 = grid.get_slot(row + 1, column + 1);
    const std::string chip3 = grid.get_slot(row + 2, column + 2);
    const std::string diagonal_pattern = chip1 + chip2 + chip3;

    return diagonal_pattern == pattern;
}

// Note: Contains hard-coding, so remember to fix this when switching to larger grids.
bool GameStatus::is_diagonal_match_from_right_to_left(const std::string& pattern, const Grid& grid) const
{
    const int row = 0;
    const int column = 2;

    const std::string chip1 = grid.get_slot(row, column);
    const std::string chip2 = grid.get_slot(row + 1, column - 1);
    const std::string chip3 = grid.get_slot(row + 2, column - 2);
    const std::string diagonal_pattern = chip1 + chip2 + chip3;
    
    return diagonal_pattern == pattern;
}

}