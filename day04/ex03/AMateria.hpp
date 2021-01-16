/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:37:28 by Kwillum           #+#    #+#             */
/*   Updated: 2021/01/13 00:23:58 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
class AMateria;
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	private:
		std::string		_type;
		unsigned int	_xp;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &toCopy);
		std::string const &		getType() const;
		unsigned int			getXP() const;
		virtual AMateria*		clone() const = 0;
		virtual void			use(ICharacter& target);
		AMateria &operator=(const AMateria &toAssign);
		virtual ~AMateria();
};

#endif
