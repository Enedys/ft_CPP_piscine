/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 22:36:47 by Kwillum          ###   ########.fr       */
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
	std::string const	&getType() const;
	int					getHP() const;
	virtual void		takeDamage(int damage);
	Enemy &operator=(const Enemy &toCopy);
};

#endif
