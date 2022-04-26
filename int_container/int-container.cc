#include "int-container.hh"

#include <iostream>
#include <memory>
#include <optional>
#include <ostream>
#include <string>

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::make_unique<int[]>(size))
{}

void MyIntContainer::print() const
{
    for (size_t i = 0; i < current_size_; i++)
    {
        i != 0 ? std::cout << " | " << this->elems_[i]
               : std::cout << this->elems_[0];
    }

    std::cout << '\n';
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ + 1 > max_size_)
        return false;

    elems_[current_size_] = elem;
    current_size_++;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (current_size_ == 0)
    {
        return std::nullopt;
    }
    else
    {
        current_size_--;
        return elems_[current_size_];
    }
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (current_size_ <= position)
    {
        return std::nullopt;
    }

    return elems_[position];
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    int idx = 0;
    for (size_t i = 0; i < current_size_; i++)
    {
        if (elems_[i] == elem)
        {
            return idx;
        }
        idx++;
    }
    return std::nullopt;
}

void MyIntContainer::sort()
{
    for (size_t idx = this->current_size_ - 1; idx > 0; idx--)
    {
        for (size_t jdx = 0; jdx < idx; jdx++)
        {
            if (this->elems_[jdx + 1] < this->elems_[jdx])
            {
                auto tmp = this->elems_[jdx];
                this->elems_[jdx] = this->elems_[jdx + 1];
                this->elems_[jdx + 1] = tmp;
            }
        }
    }
}

bool MyIntContainer::is_sorted() const
{
    for (size_t i = 0; i < current_size_; i++)
    {
        for (size_t j = i + 1; j < current_size_; j++)
        {
            if (elems_[i] > elems_[j])
            {
                return false;
            }
        }
    }
    return true;
}
