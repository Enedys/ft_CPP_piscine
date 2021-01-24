#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(56);
	a.push_back(48);
	a.push_back(6);
	a.push_back(12);
	std::vector<int>::const_iterator ef = easyfind(a, 4);

	if (ef == a.end())
		std::cout << "Element was not detected\n";
	else
		std::cout << "Detected element is " << *ef << std::endl;

	return (0);	
}