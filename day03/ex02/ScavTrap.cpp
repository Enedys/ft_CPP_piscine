#include "ScavTrap.hpp"

std::string ScavTrap::_challengeNames[5] = {
	"#bottleflipchallenge",
	"#mannequinchallenge",
	"#icebucketchallenge",
	"#10yearchallenge",
	"#kikichallenge"
};

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name, "ScavTrap")
{
	_lvl = 1;
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_armorDamageReduction = 3;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	std::cout << "ScavTrap " << name << ": Hey, best friend! Sooooo...how are things?\n";
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) : ClapTrap(toCopy)
{
	std::cout << "Copy-constructor: ScavTrap " << _name << ": Hey, best friend! Sooooo...how are things?\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &toAssign)
{
	_copy(toAssign);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << ": died\n";
}

void		ScavTrap::challengeNewcomer(void) const
{
	std::cout << "ScavTrap: " << _name << " cast challenge: " <<\
	_getRandomName(_challengeNames, _challengeNums) << std::endl;
}

int		ScavTrap::rangedAttack(std::string const &target) const
{
	std::cout << "Scav-Trap" << " " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n";
	return (_rangedAttackDamage);
}

int		ScavTrap::meleeAttack(std::string const &target) const
{
	std::cout << "Scav-Trap" << " " << _name << " attacks " << target << " at melee, causing " << _meleeAttackDamage << " points of damage!\n";
	return (_meleeAttackDamage);
}
