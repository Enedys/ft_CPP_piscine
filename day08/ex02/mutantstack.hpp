#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>()
		{
		};
		MutantStack(const MutantStack &m) : std::stack<T>(m)
		{
		};
		MutantStack<T>	&operator=(const MutantStack<T> &toCopy)
		{
			if (this == &toCopy)
				return (*this);
			static_cast<std::stack<T> >(*this) =\
			static_cast<std::stack<T> >(toCopy);
			return (*this);		
		};
		virtual ~MutantStack()
		{
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin()
		{
			return (std::stack<T>::c.begin());
		}
		iterator	end()
		{
			return (std::stack<T>::c.end());
		}

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator	cbegin() const
		{
			return (std::stack<T>::c.cbegin());
		}
		const_iterator	cend() const
		{
			return (std::stack<T>::c.cend());
		}

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin()
		{
			return (std::stack<T>::c.rbegin());
		}
		reverse_iterator	rend()
		{
			return (std::stack<T>::c.rend());
		}
		
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	crbegin() const
		{
			return (std::stack<T>::c.crbegin());
		}
		const_reverse_iterator	crend() const
		{
			return (std::stack<T>::c.crend());
		}
};

#endif
