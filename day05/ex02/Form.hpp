/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 16:15:21 by kwillum          ###   ########.fr       */
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
		bool				_signed;
		Form();
		Form &operator=(const Form &toCopy);
		int					_correctGrade();
	public:
		Form(const Form &toCopy);
		Form(std::string const &name, int grade2Sign, int grade2Exec);
		void				beSigned(const Bureaucrat &b);
		virtual void		execute(const Bureaucrat &b) const = 0;
		int					getFormGrade() const;
		int					getExecutorGrade() const;
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
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedYetException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif
