/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MaterialSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:58:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 21:32:11 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MaterialSource.hpp"

MaterialSource::MaterialSource() : _alreadyLearned(0)
{
}

MaterialSource::~MaterialSource()
{
	for (int i = 0; i < _memoryVolume; i++)
		if (_materiaSrcs[i])
			delete _materiaSrcs[i];
}

MaterialSource::MaterialSource(const MaterialSource &toCopy) : _alreadyLearned(0)
{
	for (int i = 0; i < _memoryVolume; i++)
		_materiaSrcs[i] = toCopy._materiaSrcs[i]->clone();
}

MaterialSource	&MaterialSource::operator=(const MaterialSource &toCopy)
{
	for (int i = 0; i < _memoryVolume; i++)
		if (_materiaSrcs[i])
			delete _materiaSrcs[i];
	_alreadyLearned = 0;
	for (int i = 0; i < _memoryVolume; i++)
		_materiaSrcs[i] = toCopy._materiaSrcs[i]->clone();
	return (*this);
}

void		MaterialSource::learnMateria(AMateria *m)
{
	if (_alreadyLearned < _memoryVolume && m)
		for (int i = 0; i < _memoryVolume; i++)
			if (!_materiaSrcs[i])
				_materiaSrcs[_alreadyLearned] = m;
}

AMateria*	MaterialSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _memoryVolume; i++)
		if (_materiaSrcs[i]->getType() == type)
			return (_materiaSrcs[i]->clone());
	return (NULL);
}