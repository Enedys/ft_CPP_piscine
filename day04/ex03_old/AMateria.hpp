/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:37:28 by Kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 18:56:48 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	private:
		std::string		_type;
		unsigned int	_xp;
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &toCopy);
		std::string const & getType() const;
		unsigned int getXP() const;
		virtual void use(ICharacter& target);
		virtual AMateria* clone() const = 0;
		virtual ~AMateria();
		AMateria &operator=(const AMateria &toAssign);
};