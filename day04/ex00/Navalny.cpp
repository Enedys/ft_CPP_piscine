/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Navalny.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:44:58 by Kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 01:47:51 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Navalny.hpp"

Navalny::Navalny() : Victim("Default_name")
{
}

Navalny::Navalny(const std::string &name) : Victim(name)
{
	std::cout << "Hey, I'm back in Russia!\n";
}

Navalny::~Navalny()
{
	std::cout << "Ooh no, back to the prison :(\n";
}

Navalny::Navalny(const Navalny &toCopy) : Victim(toCopy)
{
	std::cout << "Hey, I'm back in Russia!\n";
}

void	Navalny::getPolymorphed() const
{
	std::cout << _name << " has been turned into a Berlin patient!\n";
}

Navalny	&Navalny::operator=(const Navalny &toCopy)
{
	if (this == &toCopy)
		return (*this);
	_copy(toCopy);
	return (*this);
}
