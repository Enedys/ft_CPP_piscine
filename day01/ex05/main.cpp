# include <iostream>
# include "Human.hpp"

int main()
{
	Human bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
	bob.getBrain().show_iq();
	return (0);
}
