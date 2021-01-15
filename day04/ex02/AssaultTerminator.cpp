/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:42:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 16:41:46 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *\n";
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back...\n";
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &toCopy)
{
	(void)toCopy;
	std::cout << "* teleports from space *\n";
}

AssaultTerminator	&AssaultTerminator::operator=(const AssaultTerminator &toCopy)
{
	(void)toCopy;
	return (*this);
}

ISpaceMarine*		AssaultTerminator::clone() const
{
	try
	{
		ISpaceMarine	*newMarine = new AssaultTerminator;
		return (newMarine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

void				AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!\n";
}
void				AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *\n";
}

void				AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *\n";
}
