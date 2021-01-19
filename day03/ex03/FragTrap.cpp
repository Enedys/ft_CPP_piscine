#include "FragTrap.hpp"

std::string FragTrap::_atackNames[_atackNums] = {
	"Miniontrap",
	"Meat Unicycle",
	"Funzerker",
	"Mechromagician",
	"Rubber Ducky"
};

FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name, "FR4G-TP"), _vhEnergyCast(_vhCastDefault)
{
	_lvl = 1;
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 100;
	_maxEnergyPoints = 100;
	_armorDamageReduction = 5;
	_meleeAttackDamage = 30;
	_rangedAttackDamage = 20;
	std::cout << "FR4G-TP " << name << ": Hey, best friend! Sooooo...how are things?\n";
}

FragTrap::FragTrap(const FragTrap &toCopy) : ClapTrap(toCopy), _vhEnergyCast(25)
{
	std::cout << "Copy-constructor: FR4G-TP " << _name << ": Hey, best friend! Sooooo...how are things?\n";
}

FragTrap &FragTrap::operator=(const FragTrap &toAssign)
{
	std::cout << "FR4G-TP assignation operator called.\n";
	_copy(toAssign);
	_vhEnergyCast = toAssign._vhEnergyCast;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP " << _name << ": YOU! SHALL! NOT! PASS!\n";
}

int		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (_energyPoints  < _vhEnergyCast)
		std::cout << "FR4G-TP: " << _name << " to target: " << target << ". Not enought energy for skill cast :(\n";
	else
	{
		std::string	randomAttackName = _getRandomName(_atackNames, _atackNums);
		_energyPoints = _energyPoints - _vhEnergyCast;
		std::cout << "FR4G-TP: " << _name << " to target: " << target << " use " <<\
		randomAttackName << " attack.\n";
		return (2 * randomAttackName.length());
	}
	return (0);
}

int		FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << " " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n";
	return (_rangedAttackDamage);
}

int		FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << " " << _name << " attacks " << target << " at melee, causing " << _meleeAttackDamage << " points of damage!\n";
	return (_meleeAttackDamage);
}
