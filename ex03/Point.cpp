#include "Point.h"

Point::Point() : x{}, y{} {
    std::cout << "Default constructor called (Point class)" << '\n';
}

Point::Point( const float initX, const float initY ) : x{ initX }, y{ initY } {
    std::cout << "Float constructor called (Point class)" << '\n';
}

Point::Point( const Point& point ) : x{ point.x }, y{ point.y } {
    std::cout << "Copy constructor called (Point class)" << '\n';
}

// Point& Point::operator=( const Point& point ) {
//     std::cout << "Copy assignment operator called (Point class)" << '\n';
//     if ( this != &point ) {
//         this->x = point.x;
//         this->y = point.y;
//     }

//     return *this;
// }

Point::~Point() {
    std::cout << "Destructor called (Point class)" << '\n';
}

const Fixed& Point::getXObj() const {
    return x;
}

const Fixed& Point::getYObj() const {
    return y;
}


std::ostream& operator<<( std::ostream& out, const Point& point ) {
    out << "(" << point.getXObj() << ", " << point.getYObj() << ")";

    return out;
}
