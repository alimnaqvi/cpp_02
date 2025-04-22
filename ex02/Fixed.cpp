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

bool Fixed::operator>( const Fixed& fixed ) {
    return this->mFixedPointValue > fixed.mFixedPointValue;
}

bool Fixed::operator<( const Fixed& fixed ) {
    return this->mFixedPointValue < fixed.mFixedPointValue;
}

bool Fixed::operator>=( const Fixed& fixed ) {
    return this->mFixedPointValue >= fixed.mFixedPointValue;
}

bool Fixed::operator<=( const Fixed& fixed ) {
    return this->mFixedPointValue <= fixed.mFixedPointValue;
}

bool Fixed::operator==( const Fixed& fixed ) {
    return this->mFixedPointValue == fixed.mFixedPointValue;
}

bool Fixed::operator!=( const Fixed& fixed ) {
    return this->mFixedPointValue != fixed.mFixedPointValue;
}

Fixed Fixed::operator+( const Fixed& fixed ) const {
    Fixed result;
    result.setRawBits( this->mFixedPointValue + fixed.mFixedPointValue );

    return result;
}

Fixed Fixed::operator-( const Fixed& fixed ) const {
    Fixed result;
    result.setRawBits( this->mFixedPointValue - fixed.mFixedPointValue );

    return result;
}

Fixed Fixed::operator*( const Fixed& fixed ) const {
    long long rawMultiple{ static_cast<long long>( this->mFixedPointValue ) *
                           fixed.mFixedPointValue };

    Fixed result;
    result.setRawBits( static_cast<int>( rawMultiple / ( 1 << mNbFractBits ) ) );

    return result;
}

Fixed Fixed::operator/( const Fixed& fixed ) const {
    long long tempScaledUp{ static_cast<long long>( this->mFixedPointValue ) *
                            ( 1 << mNbFractBits ) };

    Fixed result;
    result.setRawBits( tempScaledUp / fixed.mFixedPointValue );

    return result;
}

Fixed& Fixed::operator++() {
    this->mFixedPointValue += 1;

    return *this;
}

Fixed Fixed::operator++( int ) {
    Fixed temp{ *this };

    ++( *this );

    return temp;
}

Fixed& Fixed::operator--() {
    this->mFixedPointValue -= 1;

    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed temp{ *this };

    --( *this );

    return temp;
}

Fixed& Fixed::min( Fixed& fixed1, Fixed& fixed2 ) {
    return fixed1 < fixed2 ? fixed1 : fixed2;
}

const Fixed& Fixed::min( const Fixed& fixed1, const Fixed& fixed2 ) {
    return fixed1.mFixedPointValue < fixed2.mFixedPointValue ? fixed1 : fixed2;
}

Fixed& Fixed::max( Fixed& fixed1, Fixed& fixed2 ) {
    return fixed1 > fixed2 ? fixed1 : fixed2;
}

const Fixed& Fixed::max( const Fixed& fixed1, const Fixed& fixed2 ) {
    return fixed1.mFixedPointValue > fixed2.mFixedPointValue ? fixed1 : fixed2;
}

std::ostream& operator<<( std::ostream& out, const Fixed& fixed ) {
    out << fixed.toFloat();

    return out;
}
