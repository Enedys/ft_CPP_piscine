/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 16:19:27 by Kwillum          ###   ########.fr       */
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
		int					_correctGrade(int grade);
		Form();
		Form &operator=(const Form &toCopy);
	protected:
		bool				_signed;
	public:
		Form(const Form &toCopy);
		Form(std::string const &name, int grade2Sign);
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
