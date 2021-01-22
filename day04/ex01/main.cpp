#include <iostream>
#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"

int main()
{
	std::cout << "\033[32m Subjects tests: \033[0m\n";
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	std::cout << "\033[32m Exeternal tests: \033[0m\n";
	Enemy* d = new SuperMutant();
	int prevEnemyHP = d->getHP();
	while (d->getHP() - me->getWeaponPtr()->getDamage() > 0)
	{
		me->attack(d);
		std::cout << *me;
		std::cout << "Current MutantHP: " << d->getHP() << std::endl;
		if (d->getHP() == prevEnemyHP)
		{
			me->equip(pf);
			me->recoverAP();
			std::cout << *me;
		}
		prevEnemyHP = d->getHP();
	}
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->attack(d);
	std::cout << *me;

	delete pr;
	delete pf;
	delete me;
	return 0;
}
