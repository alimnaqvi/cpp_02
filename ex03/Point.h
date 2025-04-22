#ifndef POINT_H
#define POINT_H

#include "Fixed.h"
#include <iostream>

#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDCYAN    "\033[1m\033[36m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define RESET       "\033[0m"

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
