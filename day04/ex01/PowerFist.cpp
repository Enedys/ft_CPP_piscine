/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 02:20:30 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
}

PowerFist::PowerFist(const PowerFist &toCopy) : AWeapon(toCopy)
{
}

void		PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *\n";
}

PowerFist	&PowerFist::operator=(const PowerFist &toCopy)
{
	if (this == &toCopy)
		return (*this);
	*((AWeapon *)this) = toCopy;
	return (*this);
}
