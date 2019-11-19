#ifndef GAME_GAME_STATUS_H
#define GAME_GAME_STATUS_H

#include "Grid.h"
#include "Player.h"
#include <string>
#include <memory>

namespace game {

class GameStatus {
public:
    GameStatus(const Grid& grid, const Player& current_player);
    bool is_game_over() const;
    bool is_draw() const;
    const std::shared_ptr<Player>& get_winner() const;
private:
    struct GameInfo {
        GameInfo(const bool running, std::shared_ptr<Player> winner = nullptr)
            : running{running}, winner{winner}
        {
        }

        bool running = false;
        std::shared_ptr<Player> winner;
    };

    GameInfo check_game_over(const Grid& grid, const Player& current_player) const;
    bool is_winning_match(const std::string& pattern, const Grid& grid) const;
    bool is_horizontal_match(const std::string& pattern, const Grid& grid) const;
    bool is_vertical_match(const std::string& pattern, const Grid& grid) const;
    bool is_diagonal_match_from_left_to_right(const std::string& pattern, const Grid& grid) const;
    bool is_diagonal_match_from_right_to_left(const std::string& pattern, const Grid& grid) const;

    GameInfo game_info_;

    constexpr static int winning_chip_count_ = 3;
};

}

#endif