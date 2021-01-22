/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 00:47:19 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 18:02:33 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const funcPtrToCreator	Intern::_formCreatorFuncArray[] = {
	ShrubberyCreationForm::formCreator,
	ShrubberyCreationForm::formCreator,
	ShrubberyCreationForm::formCreator,
	ShrubberyCreationForm::formCreator,
	PresidentialPardonForm::formCreator,
	PresidentialPardonForm::formCreator,
	PresidentialPardonForm::formCreator,
	PresidentialPardonForm::formCreator,
	RobotomyRequestForm::formCreator,
	RobotomyRequestForm::formCreator,
	RobotomyRequestForm::formCreator,
	RobotomyRequestForm::formCreator
};

const std::string		Intern::_formsName[] = {
	"shrubberycreationform",
	"shrubbery creation form",
	"shrubbery creation",
	"shrubberycreation",
	"presidentialpardonform",
	"presidential pardon form",
	"presidential pardon",
	"presidentialpardon",
	"robotomyrequestform",
	"robotomy request form",
	"robotomy request",
	"robotomyrequest"
};

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &toCopy)
{
	(void)(toCopy);
}

Form	*Intern::makeForm(const std::string &name, const std::string &target)
{
	Form		*newForm = NULL;
	std::string	nameCopy(name);

	for (size_t i = 0; i < name.length(); i++)
		nameCopy[i] = std::tolower(name[i]);

	for (int i = 0; i < _formNumbers; i++)
	{
		if (_formsName[i] == nameCopy)
		{
			try
			{
				std::cout << "Intern creates " << name << std::endl;
				newForm = _formCreatorFuncArray[i](target);
				return (newForm);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << '\n';
				return (NULL);
			}
		}
	}
	std::cout << "Error: " << "No form with such name!" << '\n';
	return (NULL);
}

Intern	&Intern::operator=(const Intern &toCopy)
{
	(void)(toCopy);
	return (*this);
}
