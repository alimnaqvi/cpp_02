#include "Point.h"
#include <iostream>
#include <iomanip>

int gTestNum {};
int gPassedTests {};

void testBSP( Point const a, Point const b, Point const c, Point const point, bool expected ) {
    std::cout << BOLDBLUE << "Test " << ++gTestNum << ": " << RESET << '\n';

    std::cout << "Testing point " << point << " on triangle with vertices: "
              << "A" << a << ", B" << b << ", C" << c << ")" << '\n';

    std::cout << "Point is " << ( expected ? "inside" : "NOT inside" ) << " the triangle." << '\n';

    if ( bsp( a, b, c, point ) == expected ) {
        std::cout << GREEN << "Test passed! :)" << RESET << '\n';
        ++gPassedTests;
    }
    else
        std::cout << RED << "Test failed! :(" << RESET << '\n';

    std::cout << "--------------------------------------" << '\n';
}

int main() {
    std::cout << "--------------------------------------" << '\n';

    // Normal case. Point inside triangle
    testBSP( Point{ -0.76f, 13.16f }, Point{ -4.13f, 5.57f }, Point{ 5.06f, 5.70f }, Point{ -1.0f, 9.0f }, true );

    // Normal case. Point outside triangle
    testBSP( Point{ 4.14, 13.38 }, Point{ 0.88, 5.82 }, Point{ 9.96901, 5.9208 }, Point{ -1, 9 }, false );

    // Normal case. Point inside triangle
    testBSP( Point{ -1, 10 }, Point{ -1, -2 }, Point{ 9.3, -2 }, Point{ 3, 2 }, true );

    // Normal case. Point outside triangle
    testBSP( Point{ -4.48, 2.86f }, Point{ -6.16, 4.12 }, Point{ 12.34, 1.7 }, Point{ 3, 2 }, false );

    // Normal case. Point inside triangle
    testBSP( Point{ -4.48f, 2.86 }, Point{ 2.04, 1.7 }, Point{ 12.34, 1.7 }, Point{ 3, 2 }, true );

    // Point slightly outside of triangle
    testBSP( Point{ -5.64, 2 }, Point{ -5.62, 5.16 }, Point{ 10.26, 2 }, Point{ 3, 1.98 }, false );

    // Point slightly inside of triangle
    testBSP( Point{ -5.64, 2 }, Point{ -5.62, 5.16 }, Point{ 10.26, 2 }, Point{ 2.34, 3.52 }, true );

    // Tiny triangle. Point inside triangle
    testBSP( Point{ -0.07413, 1.84932 }, Point{ 0.00591, 1.9632 }, Point{ 0.07413, 1.83804 }, Point{ -0.00107, 1.88155 }, true );

    // Tiny triangle. Point outside triangle
    testBSP( Point{ -0.0178, 1.86629 }, Point{ 0.02544, 1.87926 }, Point{ 0.00382, 1.85621 }, Point{ 0.00382, 1.88215 }, false );

    // Point is vertex B of triangle
    testBSP( Point{ 4.14, 13.38 }, Point{ -1, 9 }, Point{ 9.96901f, 5.9208f }, Point{ -1, 9 }, false );

    // Point is on edge BC of triangle
    testBSP( Point{ 4.14, 13.38 }, Point{ -2.38, 6.04f }, Point{ 10, 6 }, Point{ 1.42, 6 }, false );

    // Degenerate triangle. Point on the "triangle"
    testBSP( Point{ 4.22, 6 }, Point{ -2.38f, 6 }, Point{ 10, 6 }, Point{ 1.42, 6 }, false );

    // All points are zero
    testBSP( Point{ 0.0f, 0 }, Point{ 0.0, 0.0 }, Point{ 0, 0 }, Point{ 0, 0 }, false );

    // "Triangle" is all the same points. Point is outside
    testBSP( Point{ 100, 100 }, Point{ 100, 100 }, Point{ 100, 100 }, Point{ 500, 1000 }, false );

    std::cout << BOLDCYAN << gPassedTests << "/" << gTestNum << " tests passed." << RESET << '\n';
    
    return 0;
}
