#include "Player.h"
#include "InputReader.h"
#include <utility>
#include <iostream>

Player::Player(const std::string name, const Chip& chip) : name_{std::move(name)}, chip_{chip}
{
}

void Player::update(Gameboard& gameboard) const
{
    const int starting_slot = gameboard.get_starting_slot();
    const int ending_slot = gameboard.get_ending_slot();

    std::cout << "\n" << name_ << " -> Choose a slot number between " 
              << starting_slot << " - " << ending_slot << ":\n";

    const int selected_slot = InputReader::read_between<int>(starting_slot, ending_slot, 
        "*** Invalid input. Try again.\n");

    if (!gameboard.try_place(selected_slot, chip_)) {
        std::cerr << "*** Slot is already taken! Try again." << std::endl;
        return update(gameboard);
    }
}
