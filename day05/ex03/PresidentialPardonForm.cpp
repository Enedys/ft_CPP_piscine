/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/17 04:04:37 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::_name = "Presidential Pardon";

PresidentialPardonForm::PresidentialPardonForm() : Form(_name, 25, 5), _target("Deault_target")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : Form(toCopy), _target(toCopy.getTartget())
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :  Form(_name, 25, 5), _target(target)
{
}

const std::string	&PresidentialPardonForm::getTartget() const
{
	return (_target);
}

void					PresidentialPardonForm::execute(const Bureaucrat &b) const
{
	Form::execute(b);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &toCopy)
{
	(void)toCopy;
	return (*this);
}

Form				*PresidentialPardonForm::formCreator(std::string const &target)
{
	Form	*newForm = NULL;
	try
	{
		newForm = new PresidentialPardonForm(target);
	}
	catch(const std::bad_alloc& e)
	{
		throw Form::FormBadAllocException();
	}
	return (newForm);
}

