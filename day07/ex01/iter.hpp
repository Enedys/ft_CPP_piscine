#ifndef ITER_HPP
# define INTER_HPP

template <class T>
void	iter(T *array,  long long len, void (*func)(const T &member))
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}

#endif