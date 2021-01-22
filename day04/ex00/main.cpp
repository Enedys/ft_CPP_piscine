#include "Peon.hpp"
#include "Victim.hpp"
#include "Sorcerer.hpp"
#include "Navalny.hpp"

int main()
{
	std::cout << "\033[32m Sorcerer creation:\033[0m \n";
	Sorcerer volodya("Vladimir", "Bunker");
	std::cout << volodya << std::endl;

	std::cout << "\033[32m Victim tests:\033[0m \n";
	Victim jimss("Jimmy");
	std::cout << jimss << std::endl;
	Victim jos(jimss);
	std::cout << jos << std::endl;
	Victim unnamed("Unnamed");
	std::cout << unnamed;
	unnamed = jos;
	std::cout << unnamed << std::endl;

	std::cout << "\033[32m Navalny tests:\033[0m \n";
	Navalny lexa("JlexXxa Navalny");
	std::cout << lexa << std::endl;
	Navalny july("July");
	std::cout << july << std::endl;
	july = lexa;
	std::cout << july << std::endl;

	std::cout << "\033[32m Peon tests:\033[0m \n";
	Peon joes("Joes");
	std::cout << joes << std::endl;
	Peon jims("Jims");
	std::cout << jims << std::endl;
	joes = jims;
	std::cout << joes << std::endl;

	std::cout << "\033[32m Polymorph tests by reference:\033[0m \n";
	Victim *tmp = &lexa;
	Victim *tmp1 = &jimss;
	Victim *tmp2 = &jims;
	volodya.polymorph(jimss);
	volodya.polymorph(lexa);
	volodya.polymorph(jims);
	std::cout << "\n\033[32m Polymorph tests by pointer:\033[0m \n";
	volodya.polymorph(*tmp1);
	volodya.polymorph(*tmp);
	volodya.polymorph(*tmp2);

	std::cout << "\n\033[32m Subjuct tests:\033[0m \n";
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << "\n\033[32m Destructor tests:\033[0m \n";


	return 0;
}