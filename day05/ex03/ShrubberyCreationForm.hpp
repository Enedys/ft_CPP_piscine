/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/18 00:16:45 by Kwillum          ###   ########.fr       */
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
	static const std::string	_name;
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
	static Form			*formCreator(std::string const &target);
	void				execute(const Bureaucrat &b) const;
	const std::string	&getTartget() const;
	virtual ~ShrubberyCreationForm();
};

#endif
