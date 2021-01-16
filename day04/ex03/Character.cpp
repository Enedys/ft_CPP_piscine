/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:58:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/13 00:43:26 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default_name"), _alreadyEquiped(0)
{
	for (int i = 0; i < _inventoryVolume; i++)
		_materiaInventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name), _alreadyEquiped(0)
{
	for (int i = 0; i < _inventoryVolume; i++)
		_materiaInventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < _inventoryVolume; i++)
		if (_materiaInventory[i])
			delete _materiaInventory[i];
}

Character::Character(const Character &toCopy) : _name(toCopy._name)
{
	_alreadyEquiped = 0;
	for (int j = 0; j < _inventoryVolume; j++)
		_materiaInventory[j] = NULL;
	for (int i = 0; i < _inventoryVolume; i++)
	{
		if (toCopy._materiaInventory[i])
			_materiaInventory[i] = toCopy._materiaInventory[i]->clone();
		if (_materiaInventory[i])
			_alreadyEquiped++;
	}
}

void		Character::equip(AMateria* m)
{
	if (_alreadyEquiped < _inventoryVolume && m)
	{
		for (int i = 0; i < _inventoryVolume; i++)
		{
			if (!_materiaInventory[i])
			{
				_materiaInventory[i] = m;
				_alreadyEquiped++;
				break;
			}
		}
	}
}

void		Character::unequip(int idx)
{
	if (idx < _inventoryVolume && idx >= 0)
	{
		_materiaInventory[idx] = NULL;
		_alreadyEquiped--;
	}
}

void		Character::use(int idx, ICharacter& target)
{
	if (idx < _inventoryVolume && idx >= 0)
		if (_materiaInventory[idx])
			_materiaInventory[idx]->use(target);
}

std::string const &Character::getName() const
{
	return (_name);
}

Character	&Character::operator=(const Character &toCopy)
{
	_name = toCopy._name;
	_alreadyEquiped = 0;
	for (int i = 0; i < _inventoryVolume; i++)
		if (_materiaInventory[i])
			delete _materiaInventory[i];
	for (int i = 0; i < _inventoryVolume; i++)
	{
		if (toCopy._materiaInventory[i])
			_materiaInventory[i] = toCopy._materiaInventory[i]->clone();
		if (_materiaInventory[i])
			_alreadyEquiped++;
	}
	return (*this);
}
