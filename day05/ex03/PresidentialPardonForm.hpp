/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/18 00:19:02 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	const std::string			_target;
	static const std::string	_name;
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &toCopy);
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const PresidentialPardonForm &toCopy);
	PresidentialPardonForm(const std::string &target);
	void				execute(const Bureaucrat &b) const;
	static Form			*formCreator(std::string const &target);
	const std::string	&getTartget() const;
	virtual ~PresidentialPardonForm();
};

#endif
