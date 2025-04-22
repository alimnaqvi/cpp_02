#include "Fixed.h"
#include <iostream>

#define BOLDMAGENTA "\033[1m\033[35m"
#define RESET       "\033[0m"

int main( void ) {
    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << BOLDMAGENTA << a << RESET << std::endl;
    std::cout << BOLDMAGENTA << ++a << RESET << std::endl;
    std::cout << BOLDMAGENTA << a << RESET << std::endl;
    std::cout << BOLDMAGENTA << a++ << RESET << std::endl;
    std::cout << BOLDMAGENTA << a << RESET << std::endl;

    std::cout << BOLDMAGENTA << b << RESET << std::endl;

    std::cout << BOLDMAGENTA << Fixed::max( a, b ) << RESET << std::endl;

    return 0;
}
