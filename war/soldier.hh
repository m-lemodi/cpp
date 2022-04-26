//
// Created by m le modi on 25/02/2022.
//

#pragma once
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Soldier
{
public:
    Soldier(int life, int damage, const std::string& scream)
        : life_(life)
        , damage_(damage)
        , scream_(scream)
    {}

    Soldier()
        : life_(15)
        , damage_(3)
        , scream_("No pity for losers!\n")
    {}

    void attack(Soldier& s);

    void print_state() const;

    void scream() const;

    int life_;
    int damage_;
    std::string scream_;
};