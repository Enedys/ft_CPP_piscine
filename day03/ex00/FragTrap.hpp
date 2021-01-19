#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>

class FragTrap
{
	private:
		unsigned int		_lvl;
		unsigned int		_hitPoints;
		unsigned int		_maxHitPoints;
		unsigned int		_energyPoints;
		unsigned int		_maxEnergyPoints;
		unsigned int		_armorDamageReduction;
		std::string			_name;
		int					_meleeAttackDamage;
		int					_rangedAttackDamage;
		static const int	_namesNumber = 5;
		static std::string	_attackNames[_namesNumber];
		const unsigned int	_vhEnergyCast;
		const std::string	&_getRandomName(void) const;
		FragTrap();
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &toCopy);
		FragTrap	&operator=(const FragTrap &toAssign);
		int			rangedAttack(std::string const &target) const;
		int			meleeAttack(std::string const &target) const;
		void		takeDamage(unsigned int damage);
		void		beRepaired(unsigned int healthRep);
		int			vaulthunter_dot_exe(std::string const & target);
		~FragTrap();
};

#endif
