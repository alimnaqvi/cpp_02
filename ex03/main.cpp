#include "Point.h"
#include <iostream>
#include <iomanip>

void testBSP( Point const a, Point const b, Point const c, Point const point, bool expected ) {
    std::cout << "--------------------------------------" << '\n';
    std::cout << "Testing point " << point << " on triangle with vertices: "
              << "A" << a << ", B" << b << ", C" << c << ")" << '\n';
    std::cout << "Point is " << ( expected ? "inside" : "NOT inside" ) << " the triangle." << '\n';
    if ( bsp( a, b, c, point ) == expected )
        std::cout << GREEN << "Test passed! :)" << RESET << '\n';
    else
        std::cout << RED << "Test failed! :(" << RESET << '\n';
    std::cout << "--------------------------------------" << '\n';
}

int main() {
    testBSP( Point{ -0.76f, 13.16f }, Point{ -4.13f, 5.57f }, Point{ 5.06f, 5.70f },
             Point{ -1.0f, 9.0f }, true );

    return 0;
}
