#include "Pony.hpp"

Pony::Pony() : name_("default")
{
}

Pony::Pony(const std::string &pony_name) : name_(pony_name)
{
	std::cout << "Ph...Arhg...\n";
}

Pony::~Pony()
{
	std::cout << "Oh! It`s time to get out (^*^,)\'\n";
}

void	Pony::say_hello(void) const
{
	std::cout << "Hello! My name is " << this->name_ << std::endl;
}
