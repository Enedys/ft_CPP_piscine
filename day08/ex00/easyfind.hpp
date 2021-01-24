#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <vector>

template <class T>
typename T::const_iterator	easyfind(T const &a, const int& b)
{
	typename T::const_iterator beg = a.begin();
	typename T::const_iterator ender = a.end();
	return std::find(beg, ender, b);
	
}

#endif