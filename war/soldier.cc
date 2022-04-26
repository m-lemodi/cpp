//
// Created by m le modi on 25/02/2022.
//

#include "soldier.hh"

void Soldier::attack(Soldier& s)
{
    s.life_ -= damage_;
}

void Soldier::print_state() const
{
    std::cout << "I have " << life_ << " health points.\n";
}

void Soldier::scream() const
{
    std::cout << scream_;
}