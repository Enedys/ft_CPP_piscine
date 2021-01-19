#include "Zombie.hpp"

Zombie::Zombie() : name_("default_name"), type_("default_type")
{
}

Zombie::~Zombie()
{
	std::cout << this->name_ << " scream: "<<"Arghh.h..h....\n";
}

Zombie::Zombie(const std::string &name, const std::string &type = "default_type") : name_(name), type_(type)
{
}

void	Zombie::set_name(const std::string &new_name)
{
	this->name_ = new_name;
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << "< " << this->name_ << " (" << this->type_ << ")>" << " Braiiiiiiinnnssss...\n";
}
