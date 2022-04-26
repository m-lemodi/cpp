//
// Created by m le modi on 25/02/2022.
//

#pragma once

#include "soldier.hh"

class Assassin : public Soldier
{
public:
    Assassin()
        : Soldier(10, 9, "Out of the shadows!\n")
    {}
};
