/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:58:58 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 21:32:11 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _alreadyLearned(0)
{
	for (int i = 0; i < _memoryVolume; i++)
		_materiaSrcs[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _memoryVolume; i++)
		if (_materiaSrcs[i])
			delete _materiaSrcs[i];
}

MateriaSource::MateriaSource(const MateriaSource &toCopy) : _alreadyLearned(0)
{
	for (int i = 0; i < _memoryVolume; i++)
		_materiaSrcs[i] = NULL;
	for (int i = 0; i < _memoryVolume; i++)
	{
		if (toCopy._materiaSrcs[i])
		{
			_materiaSrcs[i] = toCopy._materiaSrcs[i]->clone();
			_alreadyLearned++;
		}
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &toCopy)
{
	for (int i = 0; i < _memoryVolume; i++)
		if (_materiaSrcs[i])
			delete _materiaSrcs[i];
	_alreadyLearned = 0;
	for (int i = 0; i < _memoryVolume; i++)
	{
		if (toCopy._materiaSrcs[i])
			_materiaSrcs[i] = toCopy._materiaSrcs[i]->clone();
		if (_materiaSrcs[i])
			_alreadyLearned++;
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	if (_alreadyLearned < _memoryVolume && m)
	{
		for (int i = 0; i < _memoryVolume; i++)
		{
			if (!_materiaSrcs[i])
			{
				_materiaSrcs[i] = m;
				_alreadyLearned++;
				break;
			}
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _memoryVolume; i++)
	{
		if (_materiaSrcs[i])
			if (_materiaSrcs[i]->getType() == type)
				return (_materiaSrcs[i]->clone());
	}
	return (NULL);
}
