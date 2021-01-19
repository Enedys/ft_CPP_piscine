/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/18 02:46:43 by Kwillum          ###   ########.fr       */
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
	Bureaucrat	President("President", 1);
	Bureaucrat	Ministr("Prime Minister", 50);
	Bureaucrat	CityHandler("CityHandler", 100);
	Bureaucrat	Civilian("CiviliaN", 149);
	Intern	someRandomIntern;
	Form*	testForms[15];

	testForms[0] = someRandomIntern.makeForm("robotomy request", "0");
	testForms[1] = someRandomIntern.makeForm("tomy request", "1");
	testForms[2] = someRandomIntern.makeForm("RobOtomy requesT", "2");
	testForms[3] = someRandomIntern.makeForm("robotomYrequest", "3");
	testForms[4] = someRandomIntern.makeForm("robotomy request form", "4");
	
	testForms[5] = someRandomIntern.makeForm("PresidentialPardonForm", "5");
	testForms[6] = someRandomIntern.makeForm("PresidentialPardonFormas", "6");
	testForms[7] = someRandomIntern.makeForm("Presidential PArdon Form", "7");
	testForms[8] = someRandomIntern.makeForm("PresidentialPardon", "8");
	testForms[9] = someRandomIntern.makeForm("PresidentiaL Pardon", "9");

	testForms[10] = someRandomIntern.makeForm("ShrubberyCreationForm", "10");
	testForms[11] = someRandomIntern.makeForm("ShrubberyCreationFormas", "11");
	testForms[12] = someRandomIntern.makeForm("ShruBbery crEAtion Form", "12");
	testForms[13] = someRandomIntern.makeForm("ShrubberyCReation", "13");
	testForms[14] = someRandomIntern.makeForm("ShrubbEry creaTIon", "14");


	for (int i = 0; i < 15; i++)
	{
		std::cout << "\u001b[32m [" << i << "]\u001b[0m \n";
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
