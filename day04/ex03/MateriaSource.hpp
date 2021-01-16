/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:58:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/13 00:25:41 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const int	_memoryVolume = 4;
	int					_alreadyLearned;
	AMateria			*_materiaSrcs[_memoryVolume];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &toCopy);
	void		learnMateria(AMateria *m);
	AMateria*	createMateria(std::string const & type);
	MateriaSource &operator=(const MateriaSource &toCopy);
	virtual ~MateriaSource();
};

#endif
