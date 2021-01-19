#include <iostream>
#include <string>
#include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments\n";
		return (1);
	}
	std::string	filename(argv[1]);
	std::string	find(argv[2]);
	std::string	replace(argv[3]);
	if (filename.length() == 0 || find.length() == 0 || replace.length() == 0)
	{
		std::cout << "Empty string\n";
		return (1);
	}
	Sed::sed(filename, find, replace);
	return (0);
}