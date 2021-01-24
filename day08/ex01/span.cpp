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
	_numVec.reserve(_size);
}

void	Span::addNumber(unsigned int number)
{
	if (_numVec.size() == _size)
		throw Span::ValuesPoolAreFool();
	_numVec.push_back(number);
}

unsigned int	Span::shortestSpan()
{
	if (_numVec.size() <= 1)
		throw Span::InvalidSizeForThatFuction();
	std::vector<unsigned int>	copyVec(_numVec);
	std::sort(copyVec.begin(), copyVec.end());
	std::vector<unsigned int>::const_iterator	ctr = copyVec.begin();
	std::vector<unsigned int>					_tmp;
	while (ctr + 1 != copyVec.end())
	{
		_tmp.push_back(*(ctr + 1) - *ctr);
		ctr++;
	}
	return (*std::min_element(_tmp.begin(), _tmp.end()));
}

unsigned int	Span::longestSpan()
{
	if (_numVec.size() <= 1)
		throw Span::InvalidSizeForThatFuction();
	return (*std::max_element(_numVec.begin(), _numVec.end()) -\
			*std::min_element(_numVec.begin(), _numVec.end()));
}
// std::sort(_numVec.begin(), _numVec.end());
// return (_numVec[_numVec.size() - 1] - _numVec[0]);

Span::~Span()
{
}

void	Span::appendVector(std::vector<unsigned int> &vec)
{
	if (_numVec.size() + vec.size() > _size)
		Span::ValuesPoolAreFool();
	_numVec.insert(_numVec.end(), vec.begin(), vec.end());
}

const char *Span::ValuesPoolAreFool::what() const throw()
{
	return ("Values pool are full.");
}

const char *Span::InvalidSizeForThatFuction::what() const throw()
{
	return ("Invalid array size for that function");
}

const char *Span::AppendedVectorTooBig::what() const throw()
{
	return ("Appended vector too BIG");
}
