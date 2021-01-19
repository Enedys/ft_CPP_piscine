#include "ZombieHorde.hpp"

std::string ZombieHorde::names_list[NAMES_NUM] = {
	"Danya",
	"Phill",
	"Sema",
	"Ruslan",
	"Olya",
	"Valeria",
	"Ivan"
};

int		ZombieHorde::getRandomNumber_(int min, int max) const
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
	return (static_cast<int>(std::rand() * fraction * (max - min + 1) + min));
}

ZombieHorde::ZombieHorde(int N) : zombies_number_(N)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	try
	{
		this->zombies_army_ = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			this->zombies_army_[i].set_name(names_list[getRandomNumber_(0, NAMES_NUM - 1)]);
			this->zombies_army_[i].announce();
		}
	}
	catch(const std::bad_alloc& e)
	{
		zombies_army_ = NULL;
		std::cerr << e.what() << '\n';
	}
}

ZombieHorde::~ZombieHorde()
{
	if (zombies_army_)
		delete[] zombies_army_;
	std::cout << "Zombies army are dead :(\n";
}


void	ZombieHorde::announce(void) const
{
	if (zombies_army_)
	{
		for (int i = 0; i < zombies_number_; i++)
			zombies_army_[i].announce();
	}
	else
		std::cout << "Zombies army wasn't created ;(\n";
}