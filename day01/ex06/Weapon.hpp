#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	private:
		std::string			type_;
	public:
		const std::string	&getType(void) const;
		void				setType(const std::string &new_type);
		Weapon();
		~Weapon();
		Weapon(const std::string &type);
};

# endif
