//
// Created by merli on 25/02/2022.
//
#include "parse-csv.hh"

std::vector<std::vector<std::string>> parse_csv(const std::string& file_name)
{
    std::ifstream inp;
    inp.open(file_name);
    if (!inp.is_open())
        throw std::ios_base::failure("Error opening file");

    int col = 0;
    int l = 1;
    std::vector<std::vector<std::string>> res;
    std::string what;
    std::string line;
    bool f = true;

    while (std::getline(inp, line))
    {
        std::vector<std::string> tmp;
        auto sline = std::stringstream(line);
        int count = 0;

        while (std::getline(sline, what, ','))
        {
            count++;
            if (f)
                col++;

            tmp.push_back(what);
        }
        f = false;

        if (count != col)
        {
            throw std::ios_base::failure(
                "Non consistent number of columns at line "
                + std::to_string(l));
        }
        l++;
        res.push_back(tmp);
    }

    return res;
}