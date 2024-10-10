#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>

class my_class 
{
private:
    std::string str;

public:
    my_class();
    my_class(const std::string str);
    void print_my_element() const;
};

#endif