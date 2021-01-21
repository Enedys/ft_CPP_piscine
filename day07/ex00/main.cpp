#include <iostream>
#include "whatever.hpp"
#include <iomanip>

int main()
{
	int		a = 5;
	int		b = 10;
	float	c = 1.;
	float	d = 2.28;
	double	e = 1.3333;
	double	f = 1.2545;
	char	g = 48;
	char	gg = 11;

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
