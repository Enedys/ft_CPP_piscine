#include "NinjaTrap.hpp"

int main()
{
	NinjaTrap	jopa("Jopa");
	NinjaTrap	gorno(jopa);

	jopa.beRepaired(20);
	jopa.meleeAttack("Unitaz");
	jopa.takeDamage(17);
	jopa.beRepaired(20);
	jopa.rangedAttack("Odezhda");
	jopa.takeDamage(40);
	jopa.takeDamage(40);
	jopa.takeDamage(36);
	jopa.beRepaired(228);

	ScavTrap	tolik("Tolik");
	NinjaTrap	mish("Misha");
	ClapTrap	kolya("Kolya");
	FragTrap	dima("Dimon");
	gorno.ninjaShoebox(tolik);
	gorno.ninjaShoebox(mish);
	gorno.ninjaShoebox(kolya);
	gorno.ninjaShoebox(dima);
	std::cout << std::endl;
}