#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>

class ClapTrap
{
	protected:
		std::string			_name;
		std::string			_type;
		unsigned int		_lvl;
		unsigned int		_hitPoints;
		unsigned int		_maxHitPoints;
		unsigned int		_energyPoints;
		unsigned int		_maxEnergyPoints;
		unsigned int		_armorDamageReduction;
		int					_meleeAttackDamage;
		int					_rangedAttackDamage;
		const std::string	&_getRandomName(const std::string arr[], int num) const;
		void				_copy(const ClapTrap &toCopy);
		ClapTrap();
	public:
		ClapTrap(const std::string &name, const std::string &trapType="ClapTrap");
		ClapTrap(const ClapTrap &toCopy);
		ClapTrap	&operator=(const ClapTrap &toAssign);

		int			rangedAttack(std::string const &target) const;
		int			meleeAttack(std::string const &target) const;
		void		takeDamage(unsigned int damage);
		void		beRepaired(unsigned int healthRep);
		virtual ~ClapTrap();
};

#endif
