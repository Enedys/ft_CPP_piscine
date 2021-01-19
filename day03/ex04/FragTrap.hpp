#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define _vhCastDefault 25

class FragTrap: public virtual ClapTrap
{
	private:
		FragTrap();
		static const int	_atackNums = 5;
	protected:
		static std::string	_atackNames[_atackNums];
		unsigned int		_vhEnergyCast;
	public:
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &toCopy);
		FragTrap	&operator=(FragTrap const &other);
		int			vaulthunter_dot_exe(std::string const &target);
		int			rangedAttack(std::string const &target) const;
		int			meleeAttack(std::string const &target) const;
		virtual ~FragTrap();
};

#endif
