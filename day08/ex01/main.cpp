#include "span.hpp"
# include <ctime>
# include <cstdlib>

int main()
{
	srand(time(0));;
	Span sp = Span(7);
	sp.addNumber(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "\033[32mBasic main test: \033[0m\n";
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\033[32m10k elements main test: \033[0m\n";
	Span sp1 = Span(10000);
	std::vector<unsigned int>	vec;
	for (int i = 0; i < 10000; i++)
	{
		vec.push_back(rand());
	}
	sp1.appendVector(vec);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	std::cout << "\033[32mAttempt append 10001 element: \033[31m";
	try
	{
		sp1.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\033[0m\n";

	std::cout << "\033[32mAttempt work with vectors with 0 and 1 element: \033[31m";
	try
	{
		Span sp3(0);
		sp3.longestSpan();
		sp3.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span sp4(1);
		sp4.longestSpan();
		sp4.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\033[0m\n";

	return (0);
}