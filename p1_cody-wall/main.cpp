#include "header.h"
#include "header2.h"
#include "rectangle.h"
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    show(11);
    show(22);
    area(10, 20);
    perimeter(10, 20);

    return 0;
}

/*
/Users/cody/Desktop/fall19/csis45/cmake-build-debug/csis45
Hello, World!
num = 11
num = 22
Area is 200
Perimeter is 60

Process finished with exit code 0

*/