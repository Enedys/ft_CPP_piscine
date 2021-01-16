/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 17:26:54 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default_name"), _signed(0), _grade2Sign(150), _grade2Exec(150)
{
}

Form::~Form()
{
}

Form::Form(const Form &toCopy) :
	_name(toCopy._name), _grade2Sign(toCopy._grade2Sign),\
	_signed(toCopy._signed), _grade2Exec(toCopy._grade2Exec)
{
	if (_correctGrade())
		return ;
}

Form::Form(std::string const &name, int grade2Sign = 150, int grade2Exec) :
	_name(name),  _grade2Sign(grade2Sign), _signed(false), _grade2Exec(grade2Exec)
{
	if (_correctGrade())
		return ;
}

int					Form::_correctGrade()
{
	if (_grade2Exec < 1 || _grade2Sign < 1)
		throw GradeTooHighException();
	else if (_grade2Exec > 150 || _grade2Sign > 150)
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

void		Form::execute(const Bureaucrat &b) const
{
	if (!_signed)
		throw FormNotSignedYetException();
	else if (b.getGrade() > _grade2Exec)
		throw GradeTooLowException();
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

const char	*Form::FormAlreadySignedException::what() const throw()
{
	return ("Form::Exception Form already SIGNED!\n");
}

const char	*Form::FormNotSignedYetException::what() const throw()
{
	return ("Form::Exception Form NOT SIGNED yet!\n");
}
