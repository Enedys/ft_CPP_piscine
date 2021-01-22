/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 14:39:04 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
class Form;
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		const int			_grade2Sign;
		const int			_grade2Exec;
		int					_correctGrade(int grade);
		Form();
		Form &operator=(const Form &toCopy);
		bool				_signed;
	public:
		Form(const Form &toCopy);
		Form(std::string const &name, int grade2Sign, int grade2Exec);
		void				beSigned(const Bureaucrat &b);
		int					getFormGrade() const;
		std::string const	&getFormName() const;
		bool				getSignStatus() const;
		virtual ~Form();

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
		// class FormAlreadySignedException : public std::exception
		// {
		// 	public:
		// 		virtual const char *what() const throw();
		// };
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif
