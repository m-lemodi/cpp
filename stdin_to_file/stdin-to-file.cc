#include "stdin-to-file.hh"

void stdin_to_file()
{
    std::ofstream res;
    std::string word;
    res.open("file.out");

    if (!res.is_open())
    {
        return;
    }

    while (std::cin >> word)
    {
        res << word << '\n';
    }
}