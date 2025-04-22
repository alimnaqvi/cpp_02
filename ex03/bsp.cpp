#include "Point.h"
#include "Fixed.h"

Fixed crossProductSign( const Point& a, const Point& b, const Point& p ) {
    // Vector AB = (b.x - a-x, b.y - a.y)
    Fixed vecABcoordX{ b.getXObj() - a.getXObj() };
    Fixed vecABcoordY{ b.getYObj() - a.getYObj() };

    // Vector AP = (p.x - a-x, p.y - a.y)
    Fixed vecAPcoordX{ p.getXObj() - a.getXObj() };
    Fixed vecAPcoordY{ p.getYObj() - a.getYObj() };

    // return cross product of Vector AB and Vector AP
    return ( vecABcoordX * vecAPcoordY ) - ( vecABcoordY * vecAPcoordX );
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
    Fixed signAB{ crossProductSign( a, b, point ) };
    Fixed signBC{ crossProductSign( b, c, point ) };
    Fixed signCA{ crossProductSign( c, a, point ) };

    Fixed zero{};

    bool allPositive = ( signAB > zero ) && ( signBC > zero ) && ( signCA > zero );
    bool allNegative = ( signAB < zero ) && ( signBC < zero ) && ( signCA < zero );

    return allNegative || allPositive;
}
