#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# include <iostream>

template <class T>
class Array
{
	private:
		int				_size;
		T				*_array;
	public:
		Array() : _size(0), _array(NULL) {}
		Array(int n) try : _size(n), _array(NULL)
		{
			_array = new T[n];
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		};
		Array(const Array<T> &toCopy) : _size(0), _array(NULL)
		{
			*this = toCopy;
		};
		unsigned int	size() const
		{
			return _size;
		};
		const Array<T>	&operator=(const Array<T> &toCopy)
		{
			if (this == &toCopy)
				return (*this);
			delete[] _array;
			if (toCopy._size)
			{
				_array = new T[toCopy._size];
				for (int i = 0; i < toCopy._size; i++)
					_array[i] = toCopy._array[i];
			}
			else
				_array = NULL;
			_size = toCopy._size;
			return (*this);		
		};
		~Array()
		{
			if (_array && _size)
				delete[] _array;
		}
		T	&operator[](const int index)
		{
			if (index < 0 || index >= _size)
				throw (std::exception());
			return (_array[index]);
		};
		const T	&operator[](const int index) const
		{
			if (index < 0 || index >= _size)
				throw (std::exception());
			return (_array[index]);
		};
};

#endif
