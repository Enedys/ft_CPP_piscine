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
		class ValuesPoolAreFool : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		class InvalidSizeForThatFuction : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		class AppendedVectorTooBig : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		void	appendVector(std::vector<unsigned int> &vec);
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
