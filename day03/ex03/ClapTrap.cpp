# include "ClapTrap.hpp"

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap object " << _name << " was destroyed!\n";
}

ClapTrap::ClapTrap() : _name("Default_name"), _type("ClapTrap")
{	
}

ClapTrap::ClapTrap(const std::string &name, const std::string &trapType) : _name(name), _type(trapType)
{
	_lvl = 1;
	_hitPoints = 50;
	_maxHitPoints = 100;
	_energyPoints = 20;
	_maxEnergyPoints = 80;
	_armorDamageReduction = 3;
	_meleeAttackDamage = 10;
	_rangedAttackDamage = 20;
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "ClapTrap object " << _name << " was created!\n";
}

ClapTrap::ClapTrap(const ClapTrap &toCopy)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "ClapTrap copy constructor called\n";
	*this = toCopy;
}

void				ClapTrap::_copy(const ClapTrap &toCopy)
{
	std::cout << "ClapTrap copy function called.\n";
	_name = toCopy._name;
	_type = toCopy._type;
	_lvl = toCopy._lvl;
	_hitPoints = toCopy._hitPoints;
	_maxHitPoints = toCopy._maxHitPoints;
	_energyPoints = toCopy._energyPoints;
	_maxEnergyPoints = toCopy._maxEnergyPoints;
	_armorDamageReduction = toCopy._armorDamageReduction;
	_meleeAttackDamage = toCopy._meleeAttackDamage;
	_rangedAttackDamage = toCopy._rangedAttackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &toAssign)
{
	std::cout << "ClapTrap assignation operator called.\n";
	ClapTrap::_copy(toAssign);
	return (*this);
}

const std::string			&ClapTrap::_getRandomName(const std::string names[], int num) const
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
	return names[static_cast<int>(std::rand() * fraction * num)];
}

int		ClapTrap::rangedAttack(std::string const &target) const
{
	std::cout << "ClapTrap " << " " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage!\n";
	return (_rangedAttackDamage);
}

int		ClapTrap::meleeAttack(std::string const &target) const
{
	std::cout << "ClapTrap " << " " << _name << " attacks " << target << " at melee, causing " << _meleeAttackDamage << " points of damage!\n";
	return (_meleeAttackDamage);
}

void	ClapTrap::takeDamage(unsigned int damage)
{
	if (_hitPoints == 0)
		std::cout << _type << " " << _name << " is already broken :(\n";
	else if (damage > _armorDamageReduction)
	{
		unsigned effectiveHealth = _hitPoints + _armorDamageReduction;
		unsigned int	newHitPoints = effectiveHealth < damage ? 0 : effectiveHealth - damage;
		std::cout << _type << " " << _name << " takes " << _hitPoints - newHitPoints << " damage and now has " << newHitPoints << " HP.\n";
		_hitPoints = newHitPoints;
	}
	else
		std::cout << _type << " " << _name << " was not damaged!\n";	
}

void	ClapTrap::beRepaired(unsigned int healthRep)
{
	if (_hitPoints == _maxHitPoints)
		std::cout << _type << " " << _name << " has a max HP!\n";
	else
	{
		unsigned int	futureHealth = _hitPoints + healthRep;
		unsigned int	newHitPoints = futureHealth > _maxHitPoints ? _maxHitPoints : futureHealth;
		std::cout << _type << " " << _name << " take " << newHitPoints - _hitPoints << " HP and currently has " << newHitPoints << " HP.\n";
		_hitPoints = newHitPoints;
	}
}
