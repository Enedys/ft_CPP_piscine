#include <string>
#include <iostream>

int main()
{
	std::string	msg("HI THIS IS BRAIN");
	const std::string	*ptr_to_msg = &msg;
	const std::string	&ref_to_msg = msg;
	std::cout << "String by pointer: " << *ptr_to_msg << "\nString by referebce: " << ref_to_msg << std::endl;
	return (0);
}