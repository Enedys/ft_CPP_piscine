#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main()
{
	ZombieEvent	zombie_creator;
	Zombie		simple_zombie("JIexa", "BouH");
	simple_zombie.announce();
	Zombie *new_unit = zombie_creator.newZombie("Govnar'");
	new_unit->announce();
	delete new_unit;
	zombie_creator.setZombieType(std::string("COP"));
	Zombie *ment_zombie = zombie_creator.newZombie("Stupid");
	ment_zombie->announce();
	zombie_creator.setZombieType("JIox");
	Zombie *rand_zombie = zombie_creator.randomChump();
	Zombie *rand_zombie1 = zombie_creator.randomChump();
	Zombie *rand_zombie2 = zombie_creator.randomChump();
	delete rand_zombie;
	delete rand_zombie1;
	delete rand_zombie2;
	delete ment_zombie;
	return (0);
}