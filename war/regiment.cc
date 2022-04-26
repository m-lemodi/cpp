//
// Created by merli on 25/02/2022.
//

#include "regiment.hh"

void Regiment::join_by(Regiment& r)
{
    for (auto i : r.team_)
    {
        team_.push_back(i);
    }
    r.team_.clear();
    r.size_ = 0;
}

int Regiment::count() const
{
    return size_;
}

void Regiment::add_soldier(Soldier* s)
{
    team_.push_back(s);
    size_++;
}

void Regiment::print_state() const
{
    for (auto i : team_)
    {
        i->print_state();
    }
}

void Regiment::scream() const
{
    for (auto i : team_)
    {
        i->scream();
    }
}