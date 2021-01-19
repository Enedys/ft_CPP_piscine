#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fraction = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int toCopy);
		Fixed(const float toCopy);
		Fixed(const Fixed &toCopy);
		Fixed	&operator=(const Fixed &toCopy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &ref);

#endif
