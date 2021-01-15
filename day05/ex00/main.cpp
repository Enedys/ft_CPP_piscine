/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:00:36 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 01:03:01 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void	create_bureaucreat(Bureaucrat * &b, std::string name, int grade)
{
	b = new Bureaucrat(name, grade);
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
	catch(Bureaucrat::GradeTooHighException const & e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	catch(Bureaucrat::GradeTooLowException const & e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	catch(...)
	{
		std::cout << "WTF?\n";
	}

	std::cout << *b;
	try
	{
		for (int i = 0; true; i++)
		{
			std::cout << i <<" : Increment attempt\n";
			b->incrementGrade();
		}
	}
	catch(Bureaucrat::GradeTooHighException const & e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException const & e)
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
	catch(Bureaucrat::GradeTooHighException const & e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException const & e)
	{
		std::cerr << e.what() << '\n';
	}
	delete b;
}


int		main(void)
{
	test_bureaucreat("Lexa", 228);
	test_bureaucreat("Goha", -10);
	test_bureaucreat("Miha", 0);
	test_bureaucreat("Tonya", 15);
	test_bureaucreat("Valya", 150);
	test_bureaucreat("Boss", 1);

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
