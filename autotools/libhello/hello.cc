#include "hello.hh"

#include <iostream>

void say_hello(const std::string& name)
{
    std::cout << "Hello " << name << "!" << '\n';
}
