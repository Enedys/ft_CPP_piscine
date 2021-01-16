/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 17:30:49 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const std::string RobotomyRequestForm::_name = "Presidential Pardon";

RobotomyRequestForm::RobotomyRequestForm() : Form(_name, 72, 45), _target("Deault_target")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : Form(toCopy), _target(toCopy.getTartget())
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :  Form(_name, 72, 45), _target(target)
{
}

const std::string	&RobotomyRequestForm::getTartget() const
{
	return (_target);
}

void					RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	Form::execute(b);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopy)
{
	(void)toCopy;
	return (*this);
}
