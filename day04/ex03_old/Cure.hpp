/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:14:04 by Kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 19:14:30 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	private:
	public:
		Cure();
		Cure(const Cure &toCopy);
		AMateria* clone() const;
		void use(ICharacter& target);
		Cure &operator=(const Cure &toCopy);
		virtual ~Cure();
};

#endif
