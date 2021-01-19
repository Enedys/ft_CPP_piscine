#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <cmath>
# include <cstdlib>
# include <ctime>

# define VH_EXE_COST 25

class ScavTrap
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
		static std::string	_challengeNames[_namesNumber];
		const std::string	&_getRandomName(void) const;
		ScavTrap();
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &toCopy);
		ScavTrap	&operator=(const ScavTrap &toAssign);
		int			rangedAttack(std::string const &target) const;
		int			meleeAttack(std::string const &target) const;
		void		takeDamage(unsigned int damage);
		void		beRepaired(unsigned int healthRep);
		void		challengeNewcomer() const;
		~ScavTrap();
};

#endif
