#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <exception>
# include <algorithm>

class ElementWasNotFound : std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Element was not found.");
		}

};

template <class T>
typename T::iteartor	easyfind(T &a, int b)
{
	typename T::iterator startIter = a.begin();
	typename T::iterator stopIter = a.end();
	typename T::iterator res;
	if ((res = std::find(startIter, stopIter, b)) == a.end())
		throw ElementWasNotFound();
	return res;
}

#endif