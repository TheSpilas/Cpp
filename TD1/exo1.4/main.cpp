#include "main.h"

class my_class
{
private:
    std::string sting;
public:
    my_class() : ;
    ~my_class();
};

main::main(/* args */)
{
}

main::~main()
{
}

void impr(const std::string str) {
    std::cout << str << std::endl;
}

int main() {
    impr("Hello World!");
    return 0;
}
