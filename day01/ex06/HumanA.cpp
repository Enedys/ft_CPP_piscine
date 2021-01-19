#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &weapon) : name_(name), weapon_(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}