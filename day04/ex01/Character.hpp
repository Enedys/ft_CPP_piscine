/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 02:38:44 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>
# include "Enemy.hpp"
# include "AWeapon.hpp"

class Character
{
private:
	std::string			_name;
	int					_apMax;
	int					_ap;
	int					_apRec;
	AWeapon				*_ptrWeapon;
	Character();
public:
	Character(const Character &toCopy);
	Character(std::string const & name);
	void				recoverAP();
	void				equip(AWeapon *weapon);
	void				attack(Enemy *enemy);
	int					getAP() const;
	AWeapon const		*getWeaponPtr() const;
	std::string const	&getName() const;
	Character &operator=(const Character &toCopy);
	~Character();
};

std::ostream	&operator<<(std::ostream &o, Character &ch);

#endif
