#include "Human.hpp"

const Brain	&Human::getBrain() const
{
	return (brain_);
}

const std::string	Human::identify(void) const
{
	return (brain_.identify());
}

Human::Human() : brain_(Brain())
{
}

Human::~Human()
{
}
