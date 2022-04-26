//
// Created by m le modi on 25/02/2022.
//

#pragma once

#include "soldier.hh"
class Regiment
{
public:
    Regiment() = default;

    void join_by(Regiment& r);

    int count() const;

    void add_soldier(Soldier* s);

    void print_state() const;

    void scream() const;

    int size_ = 0;
    std::vector<Soldier*> team_;
};
