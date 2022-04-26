//
// Created by merli on 25/02/2022.
//

#pragma once
template <typename T, typename F>
void my_foreach(T x, T y, F f)
{
    for (T i = x; i != y; i++)
    {
        f(*i);
    }
}