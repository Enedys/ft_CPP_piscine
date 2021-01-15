/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 22:27:12 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &toCopy) : AWeapon(toCopy)
{
}

void		PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *\n";
}

PlasmaRifle	&PlasmaRifle::operator=(const PlasmaRifle &toCopy)
{
	*((AWeapon *)this) = toCopy;
	return (*this);
}
