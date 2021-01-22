/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 15:59:10 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int		main(void)
{
	std::cout << "\033[32m Bureaucrat creation: \033[0m\n";
	Bureaucrat	President("President", 1);
	Bureaucrat	Ministr("Prime Minister", 50);
	Bureaucrat	CityHandler("CityHandler", 100);
	std::cout << "\033[32m Form creation: \033[0m\n";
	Form		mail("mail", 80, 10);
	Form		budget("Budget", 1, 10);
	Form		cityLaw("CityLaw", 120, 10);
	std::cout << "\033[32m Invalid form creation: \033[0m\n";
	try
	{
		Form		t1("test1", -1, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		t2("test2", 180, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		t3("test3", 1, 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		t4("test4", 1, -1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		t5("test5", -1, -1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		t6("test6", 10000, 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\033[32m Correct form print: \033[0m\n";

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\033[32m Signing forms lowRank: \033[0m\n";

	CityHandler.signForm(mail);
	CityHandler.signForm(budget);
	CityHandler.signForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\033[32m Signing forms middleRank: \033[0m\n";

	Ministr.signForm(mail);
	Ministr.signForm(budget);
	Ministr.signForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\033[32m Signing forms topRank: \033[0m\n";

	President.signForm(mail);
	President.signForm(budget);
	President.signForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	return (0);
}
