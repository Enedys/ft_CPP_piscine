/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:01:14 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 01:38:00 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() : _name("Default_name"), _title("Default_title")
{
}

Sorcerer::Sorcerer(const std::string &name, const std::string &title):
_name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born!\n";
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!\n";
}

Sorcerer::Sorcerer(const Sorcerer &toCopy)
{
	*this = toCopy;
	std::cout << _name << ", " << _title << ", is born!\n";
}

Sorcerer	&Sorcerer::operator=(const Sorcerer &toCopy)
{
	if (this == &toCopy)
		return (*this);
	_name = toCopy._name;
	_title = toCopy._title;
	return (*this);
}

const std::string	&Sorcerer::getName() const
{
	return (_name);
}

const std::string	&Sorcerer::getTitle() const
{
	return (_title);
}

void				Sorcerer::polymorph(const Victim &v) const
{
	v.getPolymorphed();
}

std::ostream		&operator<<(std::ostream &o, const Sorcerer &s)
{
	o << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies!\n";
	return (o);
}
