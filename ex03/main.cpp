#include "Point.h"
#include <iostream>

int main( void ) {
    Point a {1.2, 3.4};
    std::cout << "a is " << a << '\n';

    Point b {a};
    std::cout << "b is " << b << '\n';

    return 0;
}
