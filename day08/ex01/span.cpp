#include "span.hpp"

Span::Span() : _size(0)
{
}

Span &Span::operator=(const Span &toCopy)
{
	if (this == &toCopy)
		return (*this);
	_size = toCopy._size;
	_numVec = toCopy._numVec;
	return (*this);
}

Span::Span(const Span &toCopy)
{
	*this = toCopy;
}

Span::Span(unsigned int N) : _size(N)
{
}

void	Span::addNumber(unsigned int number)
{
	if (_numVec.size() == _size)
		throw std::exception();
	_numVec.push_back(number);
}

unsigned int	Span::shortestSpan()
{
	std::sort(_numVec.begin(), _numVec.end());
	std::vector<unsigned int>::const_iterator	ctr = _numVec.begin();
	std::vector<unsigned int>					_tmp;
	while (ctr + 1 != _numVec.end())
	{
		_tmp.push_back(*(ctr + 1) - *ctr);
		ctr++;
	}
	return (*std::min_element(_tmp.begin(), _tmp.end()));
}

unsigned int	Span::longestSpan()
{
	std::sort(_numVec.begin(), _numVec.end());
	return (_numVec[_numVec.size() - 1] - _numVec[0]);
}

Span::~Span()
{
}
