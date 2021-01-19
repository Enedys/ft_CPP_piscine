#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"
# include <cstring>

class SuperTrap : public FragTrap, public NinjaTrap
{
private:
	SuperTrap();
public:
	SuperTrap(const std::string &name);
	SuperTrap(const SuperTrap &toCopy);
	SuperTrap	&operator=(SuperTrap const &other);
	int			meleeAttack(std::string const &name);
	int			rangedAttack(std::string const &name);
	virtual ~SuperTrap();
};

#endif