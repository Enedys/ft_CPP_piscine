#ifndef PONY_HPP
# define PONY_HPP

# include <string>
# include <iostream>

class Pony
{
	public:
		~Pony();
		Pony(const std::string &pony_name);
		void	say_hello(void) const;
	private:
		Pony();
		const std::string	name_;
};

# endif
