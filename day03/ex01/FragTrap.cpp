#include "FragTrap.hpp"

std::string FragTrap::_attackNames[5] = {
	"Miniontrap",
	"Meat Unicycle",
	"Funzerker",
	"Mechromagician",
	"Rubber Ducky"
};

FragTrap::FragTrap() : _name("Default"), _vhEnergyCast(25)
{
}

FragTrap::FragTrap(const std::string &name) : _lvl(1), _hitPoints(100), _maxHitPoints(100),\
_energyPoints(100), _maxEnergyPoints(100), _armorDamageReduction(5), _name(name), _meleeAttackDamage(30),\
_rangedAttackDamage(20), _vhEnergyCast(25)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "FR4G-TP " << _name << ": Hey, best friend! Sooooo...how are things?\n";
}

FragTrap::FragTrap(const FragTrap &toCopy) : _vhEnergyCast(25)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "Copy constructor called\n";
	*this = toCopy;
	std::cout << "FR4G-TP " << _name << ": Hey, best friend! Sooooo...how are things?\n";
}

FragTrap &FragTrap::operator=(const FragTrap &toAssign)
{
	std::cout << "Assignation operator called.\n";
	this->_name = toAssign._name;
	this->_rangedAttackDamage = toAssign._rangedAttackDamage;
	this->_meleeAttackDamage = toAssign._meleeAttackDamage;
	this->_hitPoints = toAssign._hitPoints;
	this->_maxHitPoints = toAssign._maxHitPoints;
	this->_energyPoints = toAssign._energyPoints;
	this->_maxEnergyPoints = toAssign._maxEnergyPoints;
	this->_lvl = toAssign._lvl;
	this->_armorDamageReduction = toAssign._armorDamageReduction;
	return (*this);
}

const std::string			&FragTrap::_getRandomName(void) const
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
	return _attackNames[static_cast<int>(std::rand() * fraction * 5)];
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP " << _name << ": YOU! SHALL! NOT! PASS!\n";
}

int	FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n";
	return (_rangedAttackDamage);
}

int	FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << _name << " attacks " << target << " at melee, causing " << _meleeAttackDamage << " points of damage!\n";
	return (_meleeAttackDamage);
}

void	FragTrap::takeDamage(unsigned int damage)
{
	if (_hitPoints == 0)
		std::cout << "FR4G-TP " << _name << " is already broken :(\n";
	else if (damage > _armorDamageReduction)
	{
		unsigned effectiveHealth = _hitPoints + _armorDamageReduction;
		unsigned int	newHitPoints = effectiveHealth < damage ? 0 : effectiveHealth - damage;
		std::cout << "FR4G-TP " << _name << " takes " << _hitPoints - newHitPoints << " damage and now has " << newHitPoints << " HP.\n";
		_hitPoints = newHitPoints;
	}
	else
		std::cout << "FR4G-TP " << _name << " was not damaged!\n";	
}

void	FragTrap::beRepaired(unsigned int healthRep)
{
	if (_hitPoints == _maxHitPoints)
		std::cout << "FR4G-TP " << _name << " has a max HP!\n";
	else
	{
		unsigned int	futureHealth = _hitPoints + healthRep;
		unsigned int	newHitPoints = futureHealth > _maxHitPoints ? _maxHitPoints : futureHealth;
		std::cout << "FR4G-TP " << _name << " take " << newHitPoints - _hitPoints << " HP and currently has " << newHitPoints << " HP.\n";
		_hitPoints = newHitPoints;
	}
}

int		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (_energyPoints  < _vhEnergyCast)
		std::cout << "FR4G-TP: " << _name << " to target: " << target << ". Not enought energy for skill cast :(\n";
	else
	{
		_energyPoints = _energyPoints - _vhEnergyCast;
		std::string attackName = _getRandomName();
		std::cout << "FR4G-TP: " << _name << " to target: " << target << " use " << attackName << " attack.\n";
		return (attackName.length());
	}
	return (0);
}
