#ifndef FIXED_H
#define FIXED_H

#include <iostream>

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

  private:
    int              mFixedPointValue;
    static const int mNbFractBits;
};

std::ostream& operator<<( std::ostream& out, Fixed fixed );

#endif /* FIXED_H */
