/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 14:41:45 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default_name"), _grade2Sign(150), _grade2Exec(150), _signed(0)
{
}

Form::~Form()
{
}

Form::Form(const Form &toCopy) :
	_name(toCopy._name), _grade2Sign(toCopy._grade2Sign), _grade2Exec(toCopy._grade2Exec), _signed(toCopy._signed)
{
	if (_correctGrade(_grade2Sign))
		return ;
}

Form::Form(std::string const &name, int grade = 150, int gradeExec = 150) :
	_name(name),  _grade2Sign(grade), _grade2Exec(gradeExec), _signed(false)
{
	if (_correctGrade(_grade2Sign))
		;
	if (_correctGrade(_grade2Exec))
		;
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
	(void)toCopy;
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
