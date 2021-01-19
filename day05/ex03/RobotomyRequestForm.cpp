/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/17 04:04:06 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const std::string RobotomyRequestForm::_name = "Robotomy Request";

RobotomyRequestForm::RobotomyRequestForm() : Form(_name, 72, 45), _target("Deault_target")
{
	std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : Form(toCopy), _target(toCopy.getTartget())
{
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :  Form(_name, 72, 45), _target(target)
{
	std::srand(std::time(0));
}

const std::string	&RobotomyRequestForm::getTartget() const
{
	return (_target);
}

void					RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	Form::execute(b);
	std::cout << "* Make some noise: (\"Bzz ... RrRRrR ...\")*\n";
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized\n";
	else
		std::cout << _target << " has not been robotomized\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopy)
{
	(void)toCopy;
	return (*this);
}

Form				*RobotomyRequestForm::formCreator(std::string const &target)
{
	Form	*newForm = NULL;
	try
	{
		newForm = new RobotomyRequestForm(target);
	}
	catch(const std::bad_alloc& e)
	{
		throw Form::FormBadAllocException();
	}
	return (newForm);
}