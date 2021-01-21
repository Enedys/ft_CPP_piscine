#include <iostream>
#include <string>

#include "Array.hpp"

int main(void)
{
	Array<int> a(20);

	std::cout << "A -> ";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << "A -> ";
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = static_cast<int>(i);
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	Array<int> b(a);

	std::cout << "B + 1 -> ";
	for (size_t i = 0; i < b.size(); i++)
	{
		b[i] = static_cast<int>(i + 1);
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "A -> ";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	Array<int> c;

	c = b;
	std::cout << "C -> ";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	std::cout << "C + 1 -> ";
	for (size_t i = 0; i < c.size(); i++)
	{
		(c[i])++;
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "B -> ";
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	a = c;
	std::cout << "A -> ";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}