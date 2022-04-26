#include "word-count.hh"

#include <fstream>
#include <iostream>

ssize_t word_count(const std::string& filename)
{
    std::ifstream file_in;
    std::string word;
    ssize_t res = 0;

    file_in.open(filename);
    if (!file_in.is_open())
    {
        return -1;
    }

    while (file_in >> word)
    {
        res++;
    }
    return res;
}