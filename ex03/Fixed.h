#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
  public:
    Fixed();
    Fixed( const Fixed& fixed );
    Fixed& operator=( const Fixed& fixed );
    ~Fixed();

    Fixed( const int initInt );
    Fixed( const float initFloat );

    float toFloat( void ) const;
    int   toInt( void ) const;

    int  getRawBits( void ) const;
    void setRawBits( int const raw );

    bool operator>( const Fixed& fixed );
    bool operator<( const Fixed& fixed );
    bool operator>=( const Fixed& fixed );
    bool operator<=( const Fixed& fixed );
    bool operator==( const Fixed& fixed );
    bool operator!=( const Fixed& fixed );

    Fixed operator+( const Fixed& fixed ) const;
    Fixed operator-( const Fixed& fixed ) const;
    Fixed operator*( const Fixed& fixed ) const;
    Fixed operator/( const Fixed& fixed ) const;

    Fixed& operator++();
    Fixed& operator--();
    Fixed  operator++( int );
    Fixed  operator--( int );

    static Fixed&       min( Fixed& fixed1, Fixed& fixed2 );
    static const Fixed& min( const Fixed& fixed1, const Fixed& fixed2 );
    static Fixed&       max( Fixed& fixed1, Fixed& fixed2 );
    static const Fixed& max( const Fixed& fixed1, const Fixed& fixed2 );

  private:
    int              mFixedPointValue;
    static const int mNbFractBits;
};

std::ostream& operator<<( std::ostream& out, const Fixed& fixed );

#endif /* FIXED_H */
