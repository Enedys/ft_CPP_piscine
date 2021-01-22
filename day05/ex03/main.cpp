/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 18:22:39 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int		main(void)
{
	std::cout << "\033[32m Create Bureaucrats: \033[0m\n";
	Bureaucrat	President("President", 1);
	Bureaucrat	Ministr("Prime Minister", 50);
	Bureaucrat	CityHandler("CityHandler", 100);
	Bureaucrat	Civilian("CiviliaN", 149);
	std::cout << "\033[32m Create Intern: \033[0m\n";
	Intern	someRandomIntern;
	Form*	testForms[15];

	std::cout << "\033[32m Create Robotomy forms: \033[0m\n";
	testForms[0] = someRandomIntern.makeForm("robotomy request", "0");
	testForms[1] = someRandomIntern.makeForm("tomy request", "1");
	testForms[2] = someRandomIntern.makeForm("RobOtomy requesT", "2");
	testForms[3] = someRandomIntern.makeForm("robotomYrequest", "3");
	testForms[4] = someRandomIntern.makeForm("robotomy request form", "4");
	std::cout << "\033[32m Create Presidental forms: \033[0m\n";
	
	testForms[5] = someRandomIntern.makeForm("PresidentialPardonForm", "5");
	testForms[6] = someRandomIntern.makeForm("PresidentialPardonFormas", "6");
	testForms[7] = someRandomIntern.makeForm("Presidential PArdon Form", "7");
	testForms[8] = someRandomIntern.makeForm("PresidentialPardon", "8");
	testForms[9] = someRandomIntern.makeForm("PresidentiaL Pardon", "9");
	std::cout << "\033[32m Create Shurbbery forms: \033[0m\n";

	testForms[10] = someRandomIntern.makeForm("ShrubberyCreationForm", "10");
	testForms[11] = someRandomIntern.makeForm("ShrubberyCreationFormas", "11");
	testForms[12] = someRandomIntern.makeForm("ShruBbery crEAtion Form", "12");
	testForms[13] = someRandomIntern.makeForm("ShrubberyCReation", "13");
	testForms[14] = someRandomIntern.makeForm("ShrubbEry creaTIon", "14");

	std::cout << "\033[32m Sign and exec all forms \033[0m\n";

	for (int i = 0; i < 15; i++)
	{
		std::cout << "\033[32m [" << i << "]\033[0m \n";
		(testForms[i]) ? (std::cout << *testForms[i] << std::endl) : (std::cout << "NULL-form\n");
		if (testForms[i])
		{
			Civilian.signForm(*testForms[i]);
			Civilian.executeForm(*testForms[i]);
			CityHandler.signForm(*testForms[i]);
			CityHandler.executeForm(*testForms[i]);
			Ministr.signForm(*testForms[i]);
			Ministr.executeForm(*testForms[i]);
			President.signForm(*testForms[i]);
			President.executeForm(*testForms[i]);
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (testForms[i])
			delete testForms[i];
	}
	return (0);
}
