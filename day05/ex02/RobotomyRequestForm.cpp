/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 17:21:16 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// const std::string RobotomyRequestForm::_name = "Robotomy Request";

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request", 72, 45), _target("Deault_target")
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

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :  Form("Robotomy Request", 72, 45), _target(target)
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
