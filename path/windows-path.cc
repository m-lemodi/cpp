//
// Created by m le modi on 24/02/2022.
//

#include "windows-path.hh"

#include <array>
#include <iostream>
#include <string>
#include <vector>

WindowsPath::WindowsPath(char drive)
    : Path()
    , drive_(drive)
{}

std::string WindowsPath::to_string() const
{
    std::string res = "";
    res += drive_;
    res.append(":");

    for (size_t i = 0; i < path_.size(); ++i)
    {
        res.append("\\");
        res.append(path_[i]);
    }

    if (!final_)
        res.append("\\");
    return res;
}

bool WindowsPath::check_name(const std::string& name)
{
    if (name.find(":") != std::string::npos
        || name.find("|") != std::string::npos
        || name.find("\"") != std::string::npos
        || name.find("?") != std::string::npos
        || name.find("*") != std::string::npos)
        return false;
    return true;
}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (check_name(tail))
        return Path::join(tail, is_file);
    return *this;
}