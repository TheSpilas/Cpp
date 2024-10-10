#include "main.h"


my_class::my_class() : str("Hello World!") {}


my_class::my_class(const std::string str) : str(str) {}


void my_class::print_my_element() const {
    std::cout << str << std::endl;
}

int main() {
    my_class obj1;
    obj1.print_my_element();

    my_class obj2("Hello World!");
    obj2.print_my_element();

    return 0;
}