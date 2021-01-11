/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 01:38:59 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int Character::_apMax = 40;
int Character::_apRec = 10;

Character::Character() : _name("Default_name"), _ap(0), _ptrWeapon(NULL)
{
}

Character::Character(std::string const & name) :
_name(name), _ap(_apMax), _ptrWeapon(NULL)
{
}

Character::~Character()
{
}

Character::Character(const Character &toCopy)
{
	*this = toCopy;
}

void				Character::recoverAP()
{
	if (_ap + _apRec >= _apMax)
		_ap = _apMax;
	else
		_ap += _apRec;
}

void				Character::equip(AWeapon *weapon)
{
	_ptrWeapon = weapon;
}

void				Character::attack(Enemy *enemy)
{
	if (!_ptrWeapon || !enemy)
		return ;
	if (_ptrWeapon->getAPCost() <= _ap)
	{
		std::cout << _name << " attacks " << enemy->getType() << " with " << _ptrWeapon->getName() << std::endl;
		_ptrWeapon->attack();
		_ap -= _ptrWeapon->getAPCost();
		enemy->takeDamage(_ptrWeapon->getDamage());
		if (enemy->getHP() == 0)
			delete enemy;
	}
}

std::string const	&Character::getName() const
{
	return (_name);
}

Character	&Character::operator=(const Character &toCopy)
{
	_name = toCopy._name;
	_ap = toCopy._ap;
	_ptrWeapon = toCopy._ptrWeapon;
	return (*this);
}

int					Character::getAP() const
{
	return (_ap);
}

AWeapon const		*Character::getWeaponPtr() const
{
	return (_ptrWeapon);
}

std::ostream	&operator<<(std::ostream &o, Character &ch)
{
	AWeapon const	*weapon = ch.getWeaponPtr();
	o << ch.getName() << " has " << ch.getAP() <<" AP and ";
	if (weapon)
		o << "wields a " << weapon->getName() << std::endl;
	else
		o << "is unarmed\n";
	return (o);
}