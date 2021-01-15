/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 22:37:46 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : _hp(0), _type("Default_type")
{
}


Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
}

Enemy::Enemy(const Enemy &toCopy) : _hp(toCopy._hp), _type(toCopy._type)
{
}

Enemy::~Enemy()
{
}

std::string const	&Enemy::getType() const
{
	return (_type);
}

int					Enemy::getHP() const
{
	return (_hp);
}

void		Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	if (damage >= _hp)
		_hp = 0;
	else
		_hp -= damage;
}

Enemy	&Enemy::operator=(const Enemy &toCopy)
{
	_hp = toCopy._hp;
	_type = toCopy._type;
	return (*this);
}
