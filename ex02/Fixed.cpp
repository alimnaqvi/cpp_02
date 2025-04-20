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
    if ( this != &fixed )
        mFixedPointValue = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << '\n';
}

Fixed::Fixed( const int initInt ) : mFixedPointValue{ initInt << mNbFractBits } {
    std::cout << "Int constructor called" << '\n';
}

Fixed::Fixed( const float initFloat )
    : mFixedPointValue{ static_cast<int>( roundf( ( initFloat * ( 1 << mNbFractBits ) ) ) ) } {
    std::cout << "Float constructor called" << '\n';
}

float Fixed::toFloat( void ) const {
    return ( static_cast<float>( mFixedPointValue ) ) / ( 1 << mNbFractBits );
}

int Fixed::toInt( void ) const {
    return mFixedPointValue >> mNbFractBits;
}

int Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits member function called" << '\n';
    return mFixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    mFixedPointValue = raw;
}

std::ostream& operator<<( std::ostream& out, const Fixed& fixed ) {
    out << fixed.toFloat();

    return out;
}
