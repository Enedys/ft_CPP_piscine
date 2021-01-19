#include "Pony.hpp"

int	ponyOnTheHeap(void)
{
	Pony	*heappy_pony;

	try
	{
		heappy_pony = new Pony("HDanya");
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	heappy_pony->say_hello();
	delete heappy_pony;
	return (0);
}

void	ponyOnTheStack(void)
{
	Pony	stack_pony = Pony("SDanya");
	stack_pony.say_hello();
}

void	ponyOnTheStack(void);

int	main()
{
	std::cout << "Heap:\n\n";
	if (ponyOnTheHeap())
		std::cout << "Bad allocation problem with Pony :((";
	std::cout << "\nStack:\n\n";
	ponyOnTheStack();
	std::cout << "Done!\n";
	return (0);
}