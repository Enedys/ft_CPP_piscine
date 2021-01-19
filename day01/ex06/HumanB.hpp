#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream> 
# include "Weapon.hpp"

class HumanB
{
	private:
		const std::string	name_;
		const Weapon		*weapon_;
		HumanB();
	public:
		void				attack(void) const;
		void				setWeapon(const Weapon &new_weapon);
		HumanB(const std::string &name, const Weapon &weapon);
		HumanB(const std::string &name);
		~HumanB();
};

#endif