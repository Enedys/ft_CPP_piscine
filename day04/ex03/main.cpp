#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"


int main()
{
	std::cout << "\033[32m Subject tests (but 3 creation): \033[0m\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria *tmp0 = src->createMateria("ice");
	me->equip(tmp0);
	AMateria *tmp3 = src->createMateria("cure");
	me->equip(tmp3);
	AMateria *tmp4= src->createMateria("cure");
	me->equip(tmp4);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\033[32m Extra tests: \033[0m\n";

	AMateria *tmp00;
	if (!(tmp00 = src->createMateria("cures")))
		std::cout << "No such materia in MateriaSource.\n";
	else
		me->equip(tmp00);
	if (!(tmp00 = src->createMateria("scures")))
		std::cout << "No such materia in MateriaSource.\n";
	else
		me->equip(tmp00);
	AMateria *t1 = new Cure();
	AMateria *t2 = new Ice();
	AMateria *t3 = new Cure();
	AMateria *t4 = new Ice();
	src->learnMateria(t1);
	src->learnMateria(t2);
	src->learnMateria(t3);
	src->learnMateria(t4);
	AMateria *tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	AMateria *tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	me->use(4, *bob);

	me->use(3, *bob);
	me->unequip(3);
	me->use(3, *bob);
	
	me->use(2, *bob);
	me->unequip(2);
	me->use(2, *bob);

	me->use(1, *bob);
	me->unequip(1);
	me->use(1, *bob);

	me->use(0, *bob);
	me->unequip(0);
	me->use(0, *bob);
	
	me->equip(tmp2);
	me->use(0, *bob);

	std::cout << "\033[32m Free: \033[0m\n";

	delete bob;
	delete me;
	delete src;

	delete t3;
	delete t4;
	delete tmp0;
	delete tmp1;
	delete tmp3;
	delete tmp4;
	return 0;
}