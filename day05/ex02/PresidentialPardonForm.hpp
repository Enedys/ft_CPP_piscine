/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 18:08:52 by kwillum          ###   ########.fr       */
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
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &toCopy);
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const PresidentialPardonForm &toCopy);
	PresidentialPardonForm(const std::string &target);
	void					execute(const Bureaucrat &b) const;
	const std::string		&getTartget() const;
	virtual ~PresidentialPardonForm();
};

#endif
