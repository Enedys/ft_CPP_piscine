/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 22:15:10 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include <iostream>
# include "AWeapon.hpp"
# include <string>

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	virtual void	attack() const;
	PlasmaRifle &operator=(const PlasmaRifle &toCopy);
	virtual ~PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &toCopy);
};

#endif
