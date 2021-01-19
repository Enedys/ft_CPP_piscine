#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap	jopa("Jopa");
	FragTrap	gorno(jopa);
	FragTrap	g1("Miha");
	g1 = gorno;

	jopa.beRepaired(20);
	jopa.meleeAttack("Unitaz");
	jopa.takeDamage(17);
	jopa.beRepaired(20);
	jopa.rangedAttack("Odezhda");
	jopa.vaulthunter_dot_exe("Tom");
	jopa.vaulthunter_dot_exe("Jim");
	jopa.vaulthunter_dot_exe("Sike");
	jopa.vaulthunter_dot_exe("Joe");
	jopa.vaulthunter_dot_exe("Klim");
	jopa.takeDamage(40);
	jopa.takeDamage(40);
	jopa.takeDamage(36);
	jopa.beRepaired(228);

	ScavTrap	jopas("Popa");
	ScavTrap	gornoe(jopas);
	ScavTrap	g2("Anton");
	g2 = gornoe;

	jopas.beRepaired(20);
	jopas.meleeAttack("Unitaz");
	jopas.takeDamage(17);
	jopas.beRepaired(20);
	jopas.rangedAttack("Odezhda");
	jopas.challengeNewcomer();
	jopas.challengeNewcomer();
	jopas.challengeNewcomer();
	jopas.challengeNewcomer();
	jopas.challengeNewcomer();
	jopas.takeDamage(40);
	jopas.takeDamage(40);
	jopas.takeDamage(36);
	jopas.beRepaired(228);
}