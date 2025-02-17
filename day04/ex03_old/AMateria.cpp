/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:40:22 by Kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 18:57:44 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type), _xp(0)
{
}

AMateria::AMateria(const AMateria &toCopy) : _type(toCopy._type), _xp(toCopy._xp)
{
}

const std::string	&AMateria::getType() const
{
	return (_type);
}

unsigned int		AMateria::getXP() const
{
	return (_xp);
}

AMateria			&AMateria::operator=(const AMateria &toCopy)
{
	_xp = toCopy._xp;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	_xp += 10;
}
