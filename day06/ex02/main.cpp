#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <unistd.h>

class Base
{
	public:
		virtual ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

void	startSeed()
{
	srand(time(NULL));
}

Base	*generate(void)
{
	static int	seed = 0;
	if (!seed)
	{
		startSeed();
		seed = 1;
	}
	int	randn = rand() % 3;
	Base	*newItem = static_cast<Base *>(NULL);
	try
	{
		if (randn == 0)
		{
			newItem = new A;
			std::cout << "A was created\n";
		}
		else if (randn == 1)
		{
			newItem = new B;
			std::cout << "B was created\n";
		}
		else
		{
			newItem = new C;
			std::cout << "C was created\n";
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	return newItem;
}

void	identify_from_pointer(Base *p)
{
	if (!p)
		return ;
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
		std::cout << "Impossible cast\n";
}

void	identify_from_reference( Base & p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		static_cast<void>(a);
		std::cout << "A\n";
		return;
	}
	catch(const std::bad_cast& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		static_cast<void>(b);
		std::cout << "B\n";
		return;
	}
	catch(const std::bad_cast& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		static_cast<void>(c);
		std::cout << "C\n";
		return;
	}
	catch(const std::bad_cast& e)
	{
	}
	std::cout << "Impossible cast\n";
}


int main()
{
	Base	*p = NULL;
	for (int i = 0; i < 25; i++)
	{
		std::cout << "\033[31m Test: " << i + 1 << "\033[0m \n";
		p = generate();
		if (p)
		{
			std::cout << "By pointer: ";
			identify_from_pointer(p);
			std::cout << "By reference: ";
			identify_from_reference(*p);
			std::cout << std::endl;
			delete p;
		}
	}
	return (0);
}