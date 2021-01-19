#include "SuperTrap.hpp"

int main()
{
	std::cout << "\nOrdinary constructor:\n";
	SuperTrap	st("Jopa");
	std::cout << "\nCopy constructor:\n";
	SuperTrap	st2(st);
	std::cout << "\nAssign operator:\n";
	st2 = st;

	std::cout << "\nAttack free space\n";
	st.rangedAttack("1");
	st.meleeAttack("2");
	st2.meleeAttack("3");

	std::cout << std::endl;
}