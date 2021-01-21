#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class T>
const T&	max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

template <class T>
const T&	min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template <class T>
void		swap(T &a, T &b)
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

#endif