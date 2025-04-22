#include "Point.h"
#include <iostream>

#define BOLDMAGENTA "\033[1m\033[35m"
#define RESET       "\033[0m"

int main( void ) {
    Point a {1.2, 3.4};
    std::cout << BOLDMAGENTA << "a is " << a << RESET << '\n';

    Point b {a};
    std::cout << BOLDMAGENTA << "b is " << b << RESET << '\n';

    return 0;
}
