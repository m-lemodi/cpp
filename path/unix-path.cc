//
// Created by m le modi on 24/02/2022.
//
#include "unix-path.hh"

#include <array>
#include <iostream>
#include <string>
#include <vector>

std::string UnixPath::to_string() const
{
    std::string res;
    for (auto i : path_)
    {
        res.append("/");
        res.append(i);
    }
    if (!final_)
        res.append("/");
    return res;
}