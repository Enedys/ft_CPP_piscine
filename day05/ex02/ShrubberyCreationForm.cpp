/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 17:47:31 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_tree = 
"         v\n"
"        >X<\n"
"         A\n"
"        d$b\n"
"      .d\\$$b.\n"
"    .d$i$$\\$$b.\n"
"       d$$@b\n"
"      d\\$$$ib\n"
"    .d$$$\\$$$b\n"
"  .d$$@$$$$\\$$ib.\n"
"      d$$i$$b\n"
"     d\\$$$$@$b\n"
"  .d$@$$\\$$$$$@b.\n"
".d$$$$i$$$\\$$$$$$b.\n"
"        ###\n"
"        ###\n"
"        ### mh";


ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation", 145, 137), _target("Deault_target")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : Form(toCopy), _target(toCopy.getTartget())
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :  Form("Shrubbery Creation", 145, 137), _target(target)
{
}

const std::string	&ShrubberyCreationForm::getTartget() const
{
	return (_target);
}

void					ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	Form::execute(b);
	std::ofstream	outputFile((_target + "_shrubbery").c_str(), std::ios::trunc);
	if (!outputFile.is_open() || outputFile.fail())
		throw ShrubberyFormFileOpenException();
	outputFile << _tree;
	if (outputFile.bad())
	{
		outputFile << std::endl;
		outputFile.close();
		throw ShrubberyFormWriteErrorException();
	}
	outputFile << std::endl;
	outputFile.close();
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toCopy)
{
	(void)toCopy;
	return (*this);
}

const char *ShrubberyCreationForm::ShrubberyFormFileOpenException::what() const throw()
{
	return ("ShrubberyCreationForm::Exception error with open file!");
}

const char *ShrubberyCreationForm::ShrubberyFormWriteErrorException::what() const throw()
{
	return ("ShrubberyCreationForm::Exception error writing in file!");
}
