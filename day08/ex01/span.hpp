#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	private:
		unsigned int		_size;
		std::vector<unsigned int>	_numVec;
		Span();
	public:
		void	addNumber(unsigned int number);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		Span(unsigned int size);
		Span(const Span &toCopy);
		Span &operator=(const Span &toCopy);
		Span &operator-(const Span &toCopy);
		~Span();
};

#endif
