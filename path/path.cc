//
// Created by merli on 24/02/2022.
//
#include "path.hh"

#include <array>
#include <iostream>
#include <string>
#include <vector>

Path& Path::join(const std::string& tail, bool is_file)
{
    if (!final_)
    {
        path_.push_back(tail);
        final_ = is_file;
    }
    return *this;
}