#ifndef POINT_H
#define POINT_H

#include "Fixed.h"
#include <iostream>

class Point {
  public:
    Point();
    Point( const float initX, const float initY );
    Point( const Point& point );
    Point& operator=( const Point& point );
    ~Point();

    const Fixed& getXObj() const;
    const Fixed& getYObj() const;

  private:
    const Fixed x;
    const Fixed y;
};

std::ostream& operator<<( std::ostream& out, const Point& point );


bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif /* POINT_H */
