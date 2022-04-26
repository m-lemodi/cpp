//
// Created by m le modi on 25/02/2022.
//

#include "forward-multiplication.hh"

lambda_type create_lambda()
{
    return [](int i) { return [=](int j) { return i * j; }; };
}
