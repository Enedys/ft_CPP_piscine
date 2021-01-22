/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 17:42:47 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <string>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	const std::string			_target;
	static const std::string	_tree;
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &toCopy);
	ShrubberyCreationForm();
	class ShrubberyFormFileOpenException : std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class ShrubberyFormWriteErrorException : std::exception
	{
		public:
			virtual const char *what() const throw();
	};
public:
	ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
	ShrubberyCreationForm(const std::string &target);
	void					execute(const Bureaucrat &b) const;
	const std::string		&getTartget() const;
	virtual ~ShrubberyCreationForm();
};

#endif
