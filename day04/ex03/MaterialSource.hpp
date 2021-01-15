/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaterialSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:58:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 21:12:35 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP
# include <iostream>
# include "AMateria.hpp"
# include "IMaterialSource.hpp"

class MaterialSource : public IMateriaSource
{
private:
	MaterialSource();
	static const int	_memoryVolume = 4;
	int					_alreadyLearned;
	AMateria			*_materiaSrcs[_memoryVolume] = {};
	MaterialSource(const MaterialSource &toCopy);
public:
	void		learnMateria(AMateria *m);
	AMateria*	createMateria(std::string const & type);
	MaterialSource &operator=(const MaterialSource &toCopy);
	virtual ~MaterialSource();
};

#endif
