#include "Player.h"
#include "../io/InputReader.h"
#include <utility>
#include <iostream>

namespace game {

Player::Player(const std::string name, const Chip& chip) : name_{std::move(name)}, chip_{chip}
{
}

void Player::update(Grid& grid) const
{
    const int starting_slot = grid.starting_slot();
    const int ending_slot = grid.ending_slot();

    std::cout << *this << " -> Choose a slot number between " << starting_slot << " - " << ending_slot << ":\n";

    const int selected_slot = io::InputReader::read_between<int>(starting_slot, ending_slot, 
        "*** Invalid input. Try again.\n");

    if (!grid.try_place(selected_slot, chip_)) {
        std::cerr << "*** Slot is already taken! Try again.\n" << std::endl;
        return update(grid);
    }
}

std::ostream& operator <<(std::ostream& os, const Player& other)
{
    os << other.name_;
    return os;
}

}