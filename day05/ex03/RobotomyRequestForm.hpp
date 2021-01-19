/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/18 00:18:27 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <string>
# include "Form.hpp"
# include <ctime>

class RobotomyRequestForm : public Form
{
private:
	const std::string			_target;
	static const std::string	_name;
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &toCopy);
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const RobotomyRequestForm &toCopy);
	RobotomyRequestForm(const std::string &target);
	void				execute(const Bureaucrat &b) const;
	const std::string	&getTartget() const;
	static Form			*formCreator(std::string const &target);
	virtual ~RobotomyRequestForm();
};

#endif
