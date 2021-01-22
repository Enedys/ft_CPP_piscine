/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:28:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 18:08:55 by kwillum          ###   ########.fr       */
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
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &toCopy);
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const RobotomyRequestForm &toCopy);
	RobotomyRequestForm(const std::string &target);
	void					execute(const Bureaucrat &b) const;
	const std::string		&getTartget() const;
	virtual ~RobotomyRequestForm();
};

#endif
