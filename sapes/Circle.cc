#include "Circle.hh"
#include <memory>

void Circle::print() const {
    std::cout << "I am a circle located at ("
        << x_ << ", "
        << y_ << ") with a radius of "
        << rad_ << '\n';
    }

int Shape::get_count() {
    return count_;
}

int main () {

    {
    auto p = std::make_unique<Circle>(1,2,3);
    p->print();
    std::cout << Shape::get_count() << '\n';

    std::cout << '\n';

    Circle a(1, 1, 1);
    a.print();
    std::cout << Shape::get_count() << '\n';

    std::cout << '\n';

    Circle b(12, 13, 10);
    b.print();
    std::cout << Shape::get_count() << '\n';
}


    std::cout << '\n';
    std::cout << Shape::get_count() << '\n';
    return 0;


}
