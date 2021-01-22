/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:42:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 03:58:55 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISquad.hpp"

int main()
{
	std::cout << "\033[32m Subject tests: \033[0m\n";

	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << "\033[32m Exeternal tests: \033[0m\n";
	
	ISquad *secondSquad = new Squad;
	secondSquad->push(bob->clone());
	ISpaceMarine* tmp = secondSquad->getUnit(0);
	tmp->battleCry();
	tmp->rangedAttack();
	tmp->meleeAttack();
	*((Squad *)secondSquad) = *((Squad *)vlc);
	for (int i = 0; i < secondSquad->getCount(); ++i)
	{
		ISpaceMarine* cur = secondSquad->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << "\033[32m Destructot part: \033[0m\n";

	delete vlc;
	delete secondSquad;
	return 0;
}