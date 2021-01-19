#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string const & name) 
	: ClapTrap(name, "SuperTrap"), FragTrap(name), NinjaTrap(name)
{
	_hitPoints = 100;
	_maxHitPoints = 100;
	_armorDamageReduction = 5;
	_rangedAttackDamage = 20;
	std::cout << "SuperTrap " << _name << " constructor called.\n";
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap " << _name << " destructor called.\n";
}

SuperTrap::SuperTrap() : ClapTrap("Default"), FragTrap("Default"), NinjaTrap("Default")
{
}

SuperTrap::SuperTrap(const SuperTrap &toCopy) : ClapTrap(toCopy), FragTrap(toCopy), NinjaTrap(toCopy)
{
	std::cout << "SuperTrap " << _name << " copy-constructor called.\n";
}

SuperTrap	&SuperTrap::operator=(const SuperTrap &toAssign)
{
	std::cout << "SuperTrap assignation operator called.\n";
	*((FragTrap *)this) = toAssign;
	*((NinjaTrap *)this) = toAssign;
	return (*this);
}

int			SuperTrap::meleeAttack(std::string const &name)
{
	return (this->NinjaTrap::meleeAttack(name));
}

int			SuperTrap::rangedAttack(std::string const &name)
{
	return (this->FragTrap::rangedAttack(name));
}
