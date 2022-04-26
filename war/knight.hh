//
// Created by merli on 25/02/2022.
//

#pragma once

#include "soldier.hh"

class Knight : public Soldier
{
public:
    Knight()
        : Soldier(20, 5, "Be quick or be dead!\n")
    {}
};