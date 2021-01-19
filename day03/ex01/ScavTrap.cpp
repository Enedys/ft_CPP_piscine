#include "ScavTrap.hpp"

std::string ScavTrap::_challengeNames[5] = {
	"#bottleflipchallenge",
	"#mannequinchallenge",
	"#icebucketchallenge",
	"#10yearchallenge",
	"#kikichallenge"
};

ScavTrap::ScavTrap() : _name("Default")
{
}

ScavTrap::ScavTrap(const std::string &name) : _lvl(1), _hitPoints(100), _maxHitPoints(100),\
_energyPoints(50), _maxEnergyPoints(50), _armorDamageReduction(3), _name(name), _meleeAttackDamage(20),\
_rangedAttackDamage(15)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "ScavTrap " << _name << ": Created\n";
}

ScavTrap::ScavTrap(const ScavTrap &toCopy)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "Copy constructor called\n";
	*this = toCopy;
	std::cout << "ScavTrap " << _name << ": Created\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &toAssign)
{
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

const std::string			&ScavTrap::_getRandomName() const
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
	return _challengeNames[static_cast<int>(std::rand() * fraction * _namesNumber)];
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << ": died\n";
}

int	ScavTrap::rangedAttack(std::string const &target) const
{
	std::cout << "ScavTrap " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n";
	return (_rangedAttackDamage);
}

int	ScavTrap::meleeAttack(std::string const &target) const
{
	std::cout << "ScavTrap " << _name << " attacks " << target << " at melee, causing " << _meleeAttackDamage << " points of damage!\n";
	return (_meleeAttackDamage);
}

void	ScavTrap::takeDamage(unsigned int damage)
{
	if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " is already broken :(\n";
	else if (damage > _armorDamageReduction)
	{
		unsigned effectiveHealth = _hitPoints + _armorDamageReduction;
		unsigned int	newHitPoints = effectiveHealth < damage ? 0 : effectiveHealth - damage;
		std::cout << "ScavTrap " << _name << " takes " << _hitPoints - newHitPoints << " damage and now has " << newHitPoints << " HP.\n";
		_hitPoints = newHitPoints;
	}
	else
		std::cout << "ScavTrap " << _name << " was not damaged!\n";	
}

void	ScavTrap::beRepaired(unsigned int healthRep)
{
	if (_hitPoints == _maxHitPoints)
		std::cout << "ScavTrap " << _name << " has a max HP!\n";
	else
	{
		unsigned int	futureHealth = _hitPoints + healthRep;
		unsigned int	newHitPoints = futureHealth > _maxHitPoints ? _maxHitPoints : futureHealth;
		std::cout << "ScavTrap " << _name << " take " << newHitPoints - _hitPoints << " HP and currently has " << newHitPoints << " HP.\n";
		_hitPoints = newHitPoints;
	}
}

void	ScavTrap::challengeNewcomer() const
{
	std::cout << "ScavTrap: " << _name << " cast challenge: " << _getRandomName() << std::endl;
}
