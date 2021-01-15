/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:42:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 17:23:57 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP
# include <iostream>
# include <string> 
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &toCopy);
	ISpaceMarine* clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;
	AssaultTerminator &operator=(const AssaultTerminator &toCopy);
	~AssaultTerminator();
};

#endif
