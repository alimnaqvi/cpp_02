#include "Fixed.h"

const int Fixed::mNbFractBits = 8;

Fixed::Fixed() : mFixedPointValue{} {
    std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed( const Fixed& fixed ) : mFixedPointValue{ fixed.getRawBits() } {
    std::cout << "Copy constructor called" << '\n';
}

Fixed& Fixed::operator=( const Fixed& fixed ) {
    std::cout << "Copy assignment operator called" << '\n';
    mFixedPointValue = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << '\n';
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << '\n';
    return mFixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    mFixedPointValue = raw;
}
