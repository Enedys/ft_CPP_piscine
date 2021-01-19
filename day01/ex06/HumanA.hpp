#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <iostream> 
# include "Weapon.hpp"

class HumanA
{
	private:
		const std::string	name_;
		const Weapon		&weapon_;
		HumanA();
	public:
		void				attack(void) const;
		HumanA(const std::string &name, const Weapon &weapon);
		~HumanA();
};

#endif