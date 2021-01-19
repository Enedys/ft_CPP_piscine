#include "HumanB.hpp"

HumanB::HumanB(const std::string &name, const Weapon &weapon) :
name_(name), weapon_(&weapon)
{
}

HumanB::HumanB(const std::string &name) : name_(name), weapon_(NULL)
{
}

HumanB::HumanB() : name_("default_name")
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(const Weapon &new_weapon)
{
	weapon_ = &new_weapon;
}

void	HumanB::attack(void) const
{
	if (!weapon_)
	{
		std::cout << "Weapon type isn`t set!" << std::endl;
		return ;
	}
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}