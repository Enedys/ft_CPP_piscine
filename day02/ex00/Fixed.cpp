#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &toCopy)
{
	std::cout << "Copy constructor called\n";
	*this = toCopy;
}

Fixed &Fixed::operator=(const Fixed &toCopy)
{
	std::cout << "Assignation operator called\n";
	_value = toCopy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
