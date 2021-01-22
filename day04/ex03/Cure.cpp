/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:12:12 by Kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 04:09:20 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &toCopy) : AMateria(toCopy)
{
}

Cure	&Cure::operator=(const Cure &toCopy)
{
	if (this == &toCopy)
		return (*this);
	*((AMateria *)this) = toCopy;
	return (*this);
}

AMateria*		Cure::clone() const
{
	try
	{
		AMateria	*newMateria = new Cure;
		return (newMateria);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	
}

void			Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
