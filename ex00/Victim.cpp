/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:27:36 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 21:03:01 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim() : _name("Default_name")
{
}

Victim::Victim(const std::string &name): _name(name)
{
	std::cout << "Some random victim called " << _name << " just appeared!\n";
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!\n";
}

Victim::Victim(const Victim &toCopy)
{
	*this = toCopy;
}

void	Victim::_copy(const Victim &v)
{
	_name = v._name;
}

Victim	&Victim::operator=(const Victim &toCopy)
{
	_copy(toCopy);
	return (*this);
}

const std::string	&Victim::getName() const
{
	return (_name);
}

void				Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep!\n";
}

std::ostream &operator<<(std::ostream &o, const Victim &v)
{
	o << "I'm " << v.getName() << " and I like otters!\n";
	return (o);
}
