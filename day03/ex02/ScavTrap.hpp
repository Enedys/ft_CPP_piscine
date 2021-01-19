#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		static const int	_challengeNums = 5;
		static std::string	_challengeNames[_challengeNums];
		ScavTrap();
	public:
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &toCopy);
		ScavTrap	&operator=(ScavTrap const &other);
		int			rangedAttack(std::string const &target) const;
		int			meleeAttack(std::string const &target) const;
		void		challengeNewcomer(void) const;
		virtual ~ScavTrap();
};

#endif
