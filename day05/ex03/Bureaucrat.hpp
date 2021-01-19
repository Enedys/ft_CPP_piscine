/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 23:33:03 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 22:23:44 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
class Bureaucrat;
# include <iostream>
# include <string>
# include "Form.hpp"

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
	int					_correctGrade(int grade);
	Bureaucrat();
public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(const Bureaucrat &toCopy);
	int					getGrade() const;
	std::string const	&getName() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form &f);
	void				executeForm(const Form &f);
	Bureaucrat &operator=(const Bureaucrat &toCopy);
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	virtual ~Bureaucrat();
};

std::ostream		&operator<<(std::ostream &o, Bureaucrat const &b);

#endif
