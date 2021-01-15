/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:58:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 19:11:39 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	private:
	public:
		Ice();
		Ice(const Ice &toCopy);
		AMateria* clone() const;
		void use(ICharacter& target);
		Ice &operator=(const Ice &toCopy);
		virtual ~Ice();
};

#endif
