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

float Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fraction));
}

int Fixed::toInt(void) const
{
	return (_value >> _fraction);
}

Fixed::Fixed(const int toCopy)
{
	std::cout << "Int constructor called\n";
	if (std::abs(toCopy) >= 1 << (8 * sizeof(int) - _fraction))
	{
		std::cout << "Constructor (Int): int is overflow. Value set to 0.\n";
		_value = 0;
	}
	else
		_value = toCopy << _fraction;
}

Fixed::Fixed(const float toCopy)
{
	std::cout << "Float constructor called\n";
	_value = roundf(toCopy * (1 << _fraction));
}

std::ostream &operator<<(std::ostream &o, Fixed const &ref)
{
	o << ref.toFloat();
	return (o);
}
