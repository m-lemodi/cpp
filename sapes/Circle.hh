#include "Shape.hh"

class Circle : public Shape {
public:

    Circle (int x, int y, int radius)
        : Shape(x, y),
        rad_(radius)
    {
        std::cout << "New circle created" << '\n';
    }

    void print() const;


private:
    int rad_;

};
