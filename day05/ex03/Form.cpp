/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 18:16:40 by kwillum          ###   ########.fr       */
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
	_name(toCopy._name), _grade2Sign(toCopy._grade2Sign),\
	_grade2Exec(toCopy._grade2Exec), _signed(toCopy._signed)
{
	if (_correctGrade())
		return ;
}

Form::Form(std::string const &name, int grade2Sign = 150, int grade2Exec=150) :
	_name(name),  _grade2Sign(grade2Sign), _grade2Exec(grade2Exec), _signed(false)
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

int					Form::getExecutorGrade() const
{
	return (_grade2Exec);
}

Form	&Form::operator=(const Form &toCopy)
{
	(void)toCopy;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Form &f)
{
	o << "Form with name: " << f.getFormName() << " and FormGrade: " << \
	f.getFormGrade() << " and FormExecGrade: " << f.getExecutorGrade() <<\
	" has a currently status: " << (f.getSignStatus() ? "signed" : "not signed");
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
	return ("Form::Exception Form already SIGNED!");
}

const char	*Form::FormNotSignedYetException::what() const throw()
{
	return ("Form::Exception Form NOT SIGNED yet!");
}

const char	*Form::FormBadAllocException::what() const throw()
{
	return ("Form::Exception Bad allocation with new Form!");
}
