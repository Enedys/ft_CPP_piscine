#ifndef NINJATRAP_HPP

# define NINJATRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class NinjaTrap: public ClapTrap
{
	private:
		NinjaTrap();
	public:
		NinjaTrap(std::string const &name);
		NinjaTrap(NinjaTrap const &toCopy);
		NinjaTrap	&operator=(NinjaTrap const &other);
		int			rangedAttack(std::string const &target) const;
		int			meleeAttack(std::string const &target) const;
		void		ninjaShoebox(FragTrap &item);
		void		ninjaShoebox(ScavTrap &item);
		void		ninjaShoebox(ClapTrap &item);
		void		ninjaShoebox(NinjaTrap &item);
		virtual ~NinjaTrap();
};

#endif