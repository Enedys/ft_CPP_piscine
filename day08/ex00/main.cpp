#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> a(6);
	a.push_back(1);
	a.push_back(4);
	a.push_back(56);
	a.push_back(48);
	a.push_back(6);
	a.push_back(12);
	std::vector<int>::iterator var = easyfind(a, 4);

	if (var == a.end())
		std::cout << "Element was not detected\n";
	else
		std::cout << "Detected element is " << *var << std::endl;

	return (0);	
}