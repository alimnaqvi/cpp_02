#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
  public:
    Fixed();
    Fixed( const Fixed& fixed );
    Fixed& operator=( const Fixed& fixed );
    ~Fixed();
    int  getRawBits( void ) const;
    void setRawBits( int const raw );

  private:
    int              mFixedPointValue;
    static const int mNbFractBits;
};

#endif /* FIXED_H */
