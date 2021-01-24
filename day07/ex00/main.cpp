#include <iostream>
#include "whatever.hpp"
#include <iomanip>


class Awesome
{
	public:
		Awesome( int n ) : _n( n ) {}
		int	getN() const {return (_n); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	private:
		int _n;

};
std::ostream	&operator<<(std::ostream &o, Awesome const &b)
{
	o << b.getN();
	return (o);
}

int main()
{
	std::cout << "\033[34m Subject class test: \033[0m\n";
	{
		Awesome a(5);
		Awesome b(-3);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << min(a, b) << std::endl;
		std::cout << "max: " << max(a, b) << std::endl;
		swap(a, b);
		std::cout << "a: " << a << ", b: " << b << std::endl;
	}
	std::cout << "\033[34m Subject tests: \033[0m\n";
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	int		a = 5;
	int		b = 10;
	float	c = 1.;
	float	d = 2.28;
	double	e = 1.3333;
	double	f = 1.2545;
	char	g = 48;
	char	gg = 11;
	std::cout << "\033[34m My tests: \033[0m\n";

	std::cout << "\033[32m Max tests: \033[0m\n";
	std::cout << a << ", " << b << " max: " << max(a, b) << std::endl;
	std::cout << c << ", " << d << " max: " << max(c, d) << std::endl;
	std::cout << e << ", " << f << " max: " << max(e, f) << std::endl;
	std::cout << static_cast<int>(g) << ", " << static_cast<int>(gg) << " max: " << static_cast<int>(max(g, gg)) << std::endl;

	std::cout << "\033[32m Min tests: \033[0m\n";
	std::cout << a << ", " << b << " min: " << min(a, b) << std::endl;
	std::cout << c << ", " << d << " min: " << min(c, d) << std::endl;
	std::cout << e << ", " << f << " min: " << min(e, f) << std::endl;
	std::cout << static_cast<int>(g) << ", " << static_cast<int>(gg) << " min: " << static_cast<int>(min(g, gg)) << std::endl;

	std::cout << "\033[32m Swap tests: \033[0m\n";
	std::cout  << "Before: " << a << ", " << b << "\tAfter: ";
	swap(a, b);
	std::cout << a << ", " << b << std::endl;
	
	std::cout << "Before: " << c << ", " << d << "\tAfter: ";
	swap(c, d);
	std::cout << c << ", " << d << std::endl;
	
	std::cout << "Before: " << e << ", " << f << "\tAfter: ";
	swap(e, f);
	std::cout << e << ", " << f << std::endl;

	std::cout << "Before: " << static_cast<int>(g) << ", " << static_cast<int>(gg) << "\tAfter: ";
	swap(g, gg);
	std::cout << static_cast<int>(g) << ", " << static_cast<int>(gg) << std::endl;	
	return (0);
}
