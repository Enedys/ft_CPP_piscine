/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:24:43 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 02:44:13 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() : _name("Default_name"), _apcost(0), _damage(0)
{
}

AWeapon::~AWeapon()
{
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage):
_name(name), _apcost(apcost), _damage(damage)
{
}

std::string const	&AWeapon::getName() const
{
	return (_name);
}

int					AWeapon::getAPCost() const
{
	return (_apcost);
}

int					AWeapon::getDamage() const
{
	return (_damage);
}

AWeapon::AWeapon(const AWeapon &toCopy)
{
	*this = toCopy;
}

AWeapon	&AWeapon::operator=(const AWeapon &toCopy)
{
	if (this == &toCopy)
		return (*this);
	_name = toCopy._name;
	_apcost = toCopy._apcost;
	_damage = toCopy._damage;
	return (*this);
}
