/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/17 00:12:04 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	std::cout << "___ CREATION TEST ____\n\n";
	Bureaucrat	President("President", 1);
	Bureaucrat	Ministr("Prime Minister", 50);
	Bureaucrat	CityHandler("CityHandler", 100);
	Bureaucrat	Civilian("CiviliaN", 149);

	PresidentialPardonForm		mail("mail");
	RobotomyRequestForm			budget("Budget");
	ShrubberyCreationForm		cityLaw("CityLaw");

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

//Signing and executing
	std::cout << "\n___ SIGNIG TEST ____\n\n";

	std::cout << "\u001b[32m Civilian: \u001b[0m \n";
	Civilian.signForm(mail);
	Civilian.signForm(budget);
	Civilian.signForm(cityLaw);
	Civilian.executeForm(mail);
	Civilian.executeForm(budget);
	Civilian.executeForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\u001b[32m CityHandler: \u001b[0m\n";
	CityHandler.signForm(mail);
	CityHandler.signForm(budget);
	CityHandler.signForm(cityLaw);
	CityHandler.executeForm(mail);
	CityHandler.executeForm(budget);
	CityHandler.executeForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\u001b[32m Minister: \u001b[0m\n";
	Ministr.signForm(mail);
	Ministr.signForm(budget);
	Ministr.signForm(cityLaw);
	Ministr.executeForm(mail);
	Ministr.executeForm(budget);
	Ministr.executeForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\u001b[32m President: \u001b[0m\n";
	President.signForm(mail);
	President.signForm(budget);
	President.signForm(cityLaw);
	President.executeForm(mail);
	President.executeForm(budget);
	President.executeForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	return (0);
}
