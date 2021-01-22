/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 02:25:43 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!\n";
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh...\n";
}

void	SuperMutant::takeDamage(int damage)
{
	Enemy::takeDamage(damage - 3);
}

SuperMutant::SuperMutant(const SuperMutant &toCopy) : Enemy(toCopy)
{
}

SuperMutant	&SuperMutant::operator=(const SuperMutant &toCopy)
{
	if (this == &toCopy)
		return (*this);
	*((Enemy *)this) = toCopy;
	return (*this);
}
