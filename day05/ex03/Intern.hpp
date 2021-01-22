/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 00:47:19 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 17:56:27 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <string>
# include <locale>
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

typedef Form	*(*funcPtrToCreator)(std::string const &target);
class Intern
{
	private:
		static const int				_formNumbers = 12;
		static const std::string		_formsName[_formNumbers];
		static const funcPtrToCreator	_formCreatorFuncArray[_formNumbers];
	public:
		Intern();
		Intern(const Intern &toCopy);
		~Intern();
		Form	*makeForm(const std::string &name, const std::string &target);
		Intern &operator=(const Intern &toCopy);
};

#endif
