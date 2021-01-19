# include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap("Default_name", "NinjaTrap")
{
}

NinjaTrap::NinjaTrap(const std::string &name)
	: ClapTrap(name, "Ninja")
{
	_lvl = 1;
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_armorDamageReduction = 0;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	std::cout << "Ninja " << _name << ": Hey, tsssss...! Keep distance!\n";
}

NinjaTrap::NinjaTrap(const NinjaTrap &toCopy) : ClapTrap(toCopy)
{
	std::cout << "Copy-constructor: Ninja " << _name << ": Hey, tsssss...! Keep distance!\n";
}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &toAssign)
{
	std::cout << "Ninja assignation operator called.\n";
	_copy(toAssign);
	return (*this);
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "Ninja " << _name << ": YOU! death rattle :((\n";
}

void	NinjaTrap::ninjaShoebox(FragTrap &item)
{
	std::cout << "\nNinja " << _name << " was taken attack from vaulthater_dot_exe.\n";
	takeDamage(item.vaulthunter_dot_exe(_name));
	std::cout << "The ninja strikes back by melee and range.\n";
	item.takeDamage(_meleeAttackDamage + _rangedAttackDamage);
}

void	NinjaTrap::ninjaShoebox(ScavTrap &item)
{
	std::cout << "\nNinja " << _name << " was taken a challenge.\n";
	item.challengeNewcomer();
	std::cout << "Ninja did not complete the challenge. We take range damage :((\n";
	takeDamage(item.rangedAttack(_name));
}

void	NinjaTrap::ninjaShoebox(ClapTrap &item)
{
	std::cout << "\nNinja " << _name << " attacked ClapTrap by range.\n";
	item.takeDamage(_rangedAttackDamage);
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &item)
{
	std::cout << "\nNinja " << _name << " attacked another Ninja by melee.\n";
	item.takeDamage(_meleeAttackDamage);
}

int		NinjaTrap::rangedAttack(std::string const &target) const
{
	std::cout << "Ninja-Trap " << " " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n";
	return (_rangedAttackDamage);
}

int		NinjaTrap::meleeAttack(std::string const &target) const
{
	std::cout << "Ninja-Trap " << " " << _name << " attacks " << target << " at melee, causing " << _meleeAttackDamage << " points of damage!\n";
	return (_meleeAttackDamage);
}
