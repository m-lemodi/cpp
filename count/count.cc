#include "count.hh"

int Count::get_count () {
    return count_;
}


int main() {
    {
        Count a;
        std::cout << Count::get_count()<< '\n';
        Count b;
        std::cout << Count::get_count() << '\n';
    }


    std::cout << Count::get_count() << '\n';

    return 0;
}


