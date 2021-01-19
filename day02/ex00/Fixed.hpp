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
		Fixed(const Fixed &toCopy);
		Fixed	&operator=(const Fixed &toCopy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
