/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 21:26:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 22:18:35 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>
# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	PowerFist(const PowerFist &toCopy);
	virtual void	attack() const;
	PowerFist &operator=(const PowerFist &toCopy);
	virtual ~PowerFist();
};

#endif
