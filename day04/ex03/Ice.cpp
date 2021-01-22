/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:58:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 04:08:33 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &toCopy) : AMateria(toCopy)
{
}

Ice	&Ice::operator=(const Ice &toCopy)
{
	if (this == &toCopy)
		return (*this);
	*((AMateria *)this) = toCopy;
	return (*this);
}

AMateria*		Ice::clone() const
{
	try
	{
		AMateria	*newMateria = new Ice;
		return (newMateria);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	
}

void			Ice::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
