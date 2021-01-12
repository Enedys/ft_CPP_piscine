/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:42:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 16:42:26 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!\n";
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh...\n";
}

TacticalMarine::TacticalMarine(const TacticalMarine &toCopy)
{
	(void)toCopy;
	std::cout << "Tactical Marine ready for battle!\n";
}

ISpaceMarine*	TacticalMarine::clone() const
{
	try
	{
		ISpaceMarine	*newMarine = new TacticalMarine;
		return (newMarine);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

void			TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!\n";
}

void			TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *\n";
}

void			TacticalMarine::meleeAttack() const
{
	std::cout <<  "* attacks with a chainsword *\n";
}

TacticalMarine	&TacticalMarine::operator=(const TacticalMarine &toCopy)
{
	(void)toCopy;
	return (*this);
}
