#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
	ScavTrap	jopa("Jopa");
	ScavTrap	gorno(jopa);
	ScavTrap	tolik("Tolya");

	tolik = gorno;
	jopa.beRepaired(20);
	jopa.meleeAttack("Unitaz");
	jopa.takeDamage(17);
	jopa.beRepaired(20);
	jopa.rangedAttack("Odezhda");
	jopa.challengeNewcomer();
	jopa.challengeNewcomer();
	jopa.challengeNewcomer();
	jopa.challengeNewcomer();
	jopa.challengeNewcomer();
	jopa.takeDamage(40);
	jopa.takeDamage(40);
	jopa.takeDamage(36);
	jopa.beRepaired(228);
	}

	{
	FragTrap	jopa("Jopa");
	FragTrap	lexa( jopa );
	FragTrap	miha("Miha");
	miha = lexa;

	jopa.beRepaired(20);
	jopa.meleeAttack("Unitaz");
	jopa.takeDamage(17);
	jopa.beRepaired(20);
	jopa.rangedAttack("Odezhda");
	jopa.vaulthunter_dot_exe("Tom");
	jopa.vaulthunter_dot_exe("Jim");
	jopa.vaulthunter_dot_exe("Mike");
	jopa.vaulthunter_dot_exe("Mike");
	jopa.vaulthunter_dot_exe("Mike");
	jopa.takeDamage(40);
	jopa.takeDamage(40);
	jopa.takeDamage(36);
	jopa.beRepaired(228);
	}
}