/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 02:27:48 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>
# include <string>

class Enemy
{
private:
	int			_hp;
	std::string	_type;
	Enemy();
public:
	Enemy(const Enemy &toCopy);
	Enemy(int hp, const std::string &name);
	virtual ~Enemy();
	int					getHP() const;
	std::string const	&getType() const;
	virtual void		takeDamage(int damage);
	Enemy &operator=(const Enemy &toCopy);
};

#endif
