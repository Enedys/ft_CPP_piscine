/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:48:30 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 21:06:28 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon() : Victim("Default_name")
{
}

Peon::Peon(const std::string &name) : Victim(name)
{
	std::cout << "Zog zog.\n";
}

Peon::~Peon()
{
	std::cout << "Bleuark...\n";
}

Peon::Peon(const Peon &toCopy) : Victim(toCopy)
{
}

void	Peon::getPolymorphed() const
{
	std::cout << _name << " has been turned into a pink pony!\n";
}

Peon	&Peon::operator=(const Peon &toCopy)
{
	_copy(toCopy);
	return (*this);
}
