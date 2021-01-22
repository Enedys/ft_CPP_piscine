/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:00:36 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 04:51:25 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void	create_bureaucreat(Bureaucrat * &b, std::string name, int grade)
{
	b = new Bureaucrat(name, grade);
	std::cout << std::endl;
}

void	test_bureaucreat(std::string name, int grade)
{
	std::cout << "Test: " << name << ", grade: " << grade << std::endl;
	Bureaucrat *b = NULL;
	try
	{
		std::cout << "Creation attempt\n";
		create_bureaucreat(b, name, grade);
	}
	catch(std::exception const & e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	catch(...)
	{
		std::cout << "WTF?\n";
	}

	std::cout << *b << std::endl;
	try
	{
		for (int i = 0; true; i++)
		{
			std::cout << i <<" : Increment attempt\n";
			b->incrementGrade();
		}
	}
	catch(std::exception const & e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		for (int i = 0; true; i++)
		{
			std::cout << i <<" : Decrement attempt\n";
			b->decrementGrade();
		}
	}
	catch(std::exception const & e)
	{
		std::cerr << e.what() << '\n';
	}
	delete b;
}


int		main(void)
{
	std::cout << "\033[32m Tests bad grade1: \033[0m\n";
	test_bureaucreat("Lexa", 228);
	std::cout << "\033[32m Tests bad grade2: \033[0m\n";
	test_bureaucreat("Goha", -10);
	std::cout << "\033[32m Tests bad grade3: \033[0m\n";
	test_bureaucreat("Miha", 0);
	std::cout << "\033[32m Tests correct grade1: \033[0m\n";
	test_bureaucreat("Tonya", 15);
	std::cout << "\033[32m Tests correct grade2: \033[0m\n";
	test_bureaucreat("Valya", 150);
	std::cout << "\033[32m Tests correct grade3: \033[0m\n";
	test_bureaucreat("Boss", 1);

	std::cout << "\033[32m Tests to output: \033[0m\n";
	Bureaucrat a("One", 2);
	Bureaucrat b("Two", 22);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	b = a;
	std::cout << b << std::endl;
	Bureaucrat c(b);
	std::cout << c << std::endl;
	return (0);
}
