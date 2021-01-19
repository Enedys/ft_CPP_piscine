#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
	private:
		const Brain			brain_;
	public:
		Human();
		const Brain			&getBrain() const;
		const std::string	identify(void) const;
		~Human();
};

#endif