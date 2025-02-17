/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:24:43 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 02:44:07 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>
# include <string>

class AWeapon
{
private:
	AWeapon();
	std::string			_name;
	int					_apcost;
	int					_damage;
public:
	AWeapon(const AWeapon &toCopy);
	AWeapon(std::string const &name, int apcost, int damage);
	std::string const	&getName() const;
	int					getAPCost() const;
	int					getDamage() const;
	virtual void attack() const = 0;
	AWeapon &operator=(const AWeapon &toCopy);
	virtual ~AWeapon();
};

#endif
