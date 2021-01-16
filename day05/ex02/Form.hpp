/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:13:00 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/16 17:22:26 by Kwillum          ###   ########.fr       */
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
		Form();
		Form &operator=(const Form &toCopy);
		int					_correctGrade();
	protected:
		bool				_signed;
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
