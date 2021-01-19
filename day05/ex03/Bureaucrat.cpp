/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:33:03 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 23:02:23 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name ("Default_name"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade = 150) : _name(name)
{
	if (_correctGrade(grade))
		_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy) : _name(toCopy._name)
{
	if (_correctGrade(toCopy._grade))
		_grade = toCopy._grade;
}

int				Bureaucrat::_correctGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (1);
}

void			Bureaucrat::decrementGrade()
{
	if (_correctGrade(_grade + 1))
		_grade++;
}

void			Bureaucrat::incrementGrade()
{
	if (_correctGrade(_grade - 1))
		_grade--;
}

int				Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string const	&Bureaucrat::getName() const
{
	return (_name);
}

void				Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signs " << f.getFormName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << _name << " cannot sign " << f.getFormName()\
		<< " because " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm(const Form &f)
{
	try
	{
		f.execute(*this);
		std::cout << _name << " executes " << f.getFormName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << _name << " cannot execute " << f.getFormName()\
		<< " because " << e.what() << std::endl;
	}
}

const char		*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::Exception Too HIGH grade!\n");
}

const char		*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::Exception Too LOW grade!\n");
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &toCopy)
{
	if (_correctGrade(toCopy._grade))
		_grade = toCopy._grade;
	return (*this);
}

std::ostream		&operator<<(std::ostream &o, Bureaucrat const &b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (o);
}
