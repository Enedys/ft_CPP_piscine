/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 16:26:07 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	President("President", 1);
	Bureaucrat	Ministr("Prime Minister", 50);
	Bureaucrat	CityHandler("CityHandler", 100);

	Form		mail("mail", 80);
	Form		budget("Budget", 1);
	Form		cityLaw("CityLaw", 120);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

//	Uncorret forms:
	try
	{
		Form		w("ErrorForm", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		w("ErrorForm1", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

//Signing
	CityHandler.signForm(mail);
	CityHandler.signForm(budget);
	CityHandler.signForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	Ministr.signForm(mail);
	Ministr.signForm(budget);
	Ministr.signForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	President.signForm(mail);
	President.signForm(budget);
	President.signForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	return (0);
}
