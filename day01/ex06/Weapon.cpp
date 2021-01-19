#include "Weapon.hpp"

Weapon::Weapon() : type_("default_type")
{
}

Weapon::Weapon(const std::string &type) : type_(type)
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType(void) const
{
	return (type_);
}

void				Weapon::setType(const std::string &new_type)
{
	type_ = new_type;
}