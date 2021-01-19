#include "ZombieEvent.hpp"

std::string ZombieEvent::names_list_[NAMES_NUM] = {
	"Danya",
	"Phill",
	"Sema",
	"Ruslan",
	"Olya",
	"Valeria",
	"Ivan"
};

ZombieEvent::ZombieEvent() : type_("default_type")
{
	std::srand(static_cast<unsigned int>(std::time(0)));
}

ZombieEvent::~ZombieEvent()
{
}

void	ZombieEvent::setZombieType(const std::string &type)
{
	this->type_ = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie	*newZomb = new Zombie(name, this->type_);
	return (newZomb);
}

int		ZombieEvent::getRandomNumber_(int min, int max) const
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
	return (static_cast<int>(std::rand() * fraction * (max - min + 1) + min));
}

Zombie	*ZombieEvent::randomChump(void)
{
	int		name_index = this->getRandomNumber_(0, NAMES_NUM - 1);
	Zombie	*new_chump = newZombie(this->names_list_[name_index]);
	new_chump->announce();
	return (new_chump);
}
