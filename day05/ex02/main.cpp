/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 17:50:38 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int		main(void)
{
	std::cout << "\033[32m Creation tests: \033[0m\n";
	Bureaucrat	President("President", 1);
	Bureaucrat	Ministr("Prime Minister", 50);
	Bureaucrat	CityHandler("CityHandler", 100);
	Bureaucrat	Civilian("CiviliaN", 149);

	PresidentialPardonForm		mail("mail");
	RobotomyRequestForm			budget("Budget");
	ShrubberyCreationForm		cityLaw("CityLaw");
	ShrubberyCreationForm		cityLawMisnister("CityLawMinister");
	ShrubberyCreationForm		cityLawPresident("CityLawPresident");



	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;
	std::cout << cityLawMisnister << std::endl;
	std::cout << cityLawPresident << std::endl;

	std::cout << "\033[34m Signing tests: \033[0m\n";

	std::cout << "\033[32m Civilian: \033[0m \n";
	Civilian.signForm(mail);
	Civilian.signForm(budget);
	Civilian.signForm(cityLaw);
	Civilian.executeForm(mail);
	Civilian.executeForm(budget);
	Civilian.executeForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\033[32m CityHandler: \033[0m\n";
	CityHandler.signForm(mail);
	CityHandler.signForm(budget);
	CityHandler.signForm(cityLaw);
	CityHandler.executeForm(mail);
	CityHandler.executeForm(budget);
	CityHandler.executeForm(cityLaw);

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\033[32m Minister: \033[0m\n";
	Ministr.signForm(mail);
	Ministr.signForm(budget);
	Ministr.signForm(cityLaw);
	Ministr.executeForm(mail);
	Ministr.executeForm(budget);
	Ministr.executeForm(cityLaw);
	Ministr.signForm(cityLawMisnister);
	Ministr.executeForm(cityLawMisnister);	


	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	std::cout << "\033[32m President: \033[0m\n";
	President.signForm(mail);
	President.signForm(budget);
	President.signForm(cityLaw);
	President.executeForm(mail);
	President.executeForm(budget);
	President.executeForm(cityLaw);
	President.signForm(cityLawPresident);
	President.executeForm(cityLawPresident);	

	std::cout << mail << std::endl;
	std::cout << budget << std::endl;
	std::cout << cityLaw << std::endl;

	return (0);
}
