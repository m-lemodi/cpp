#include <iostream>
class Shape
{
public:
    Shape()
        : x_(0)
        , y_(0)
    {
        count_++;
        std::cout << "New shape created\n";
    }

    Shape(int x, int y)
        : x_(x)
        , y_(y)
    {
        count_++;
        std::cout << "New shape created (" << x_ << ", " << y_ << ")\n";
    }

    virtual ~Shape()
    {count_--;}

    static int get_count();
    virtual void print() const = 0;

    void translate(int tx, int ty)
    {
        x_ += tx;
        y_ += ty;
    }

protected:
    int x_;
    int y_;
    static int count_;
};

int Shape::count_ = 0;
