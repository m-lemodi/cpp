#pragma once
#include <iostream>
#include <string>

class Count {
public:
    Count()
    {count_++;};

    static int get_count();

    ~Count() {
        count_--;
    }

private:
    static int count_;
};

int Count::count_ = 0;
