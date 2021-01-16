/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 16:24:28 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default_name"), _signed(0), _grade2Sign(150)
{
}

Form::~Form()
{
}

Form::Form(const Form &toCopy) :
	_name(toCopy._name), _grade2Sign(toCopy._grade2Sign), _signed(toCopy._signed)
{
	if (_correctGrade(_grade2Sign))
		return ;
}

Form::Form(std::string const &name, int grade = 150) :
	_name(name),  _grade2Sign(grade), _signed(false)
{
	if (_correctGrade(_grade2Sign))
		return ;
}

int					Form::_correctGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (1);
}

void				Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _grade2Sign)
		throw GradeTooLowException();
	else
		_signed = true;
}

int					Form::getFormGrade() const
{
	return (_grade2Sign);
}

std::string const	&Form::getFormName() const
{
	return (_name);
}

bool				Form::getSignStatus() const
{
	return (_signed);
}

Form	&Form::operator=(const Form &toCopy)
{
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Form &f)
{
	o << "Form with name: " << f.getFormName() << " and FormGrade: " << \
	f.getFormGrade() << " has a currently status: " << (f.getSignStatus() ? "signed" : "not signed");
	return (o);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form::Exception Too HIGH grade!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form::Exception Too LOW grade!");
}



	// if (_signed)
	// 	throw FormAlreadySignedException(); 
// const char	*Form::FormAlreadySignedException::what() const throw()
// {
// 	return ("Form::Exception Form already SIGNED!\n");
// }
