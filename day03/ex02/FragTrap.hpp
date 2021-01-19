#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define _vhCastDefault 25

class FragTrap: public ClapTrap
{
	private:
		static const int	_atackNums = 5;
		static std::string	_atackNames[_atackNums];
		unsigned int		_vhEnergyCast;
		FragTrap();
	public:
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &toCopy);
		FragTrap	&operator=(FragTrap const &other);
		int			rangedAttack(std::string const &target) const;
		int			meleeAttack(std::string const &target) const;
		int			vaulthunter_dot_exe(std::string const &target);
		virtual ~FragTrap();
};

#endif
