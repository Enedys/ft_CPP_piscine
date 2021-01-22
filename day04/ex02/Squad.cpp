/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:42:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 03:55:03 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad() : _unitsInSquad(0), _listSquad(NULL)
{
}

Squad::~Squad()
{
	removeList(_listSquad);
}

int				Squad::getCount() const
{
	return (_unitsInSquad);
}

ISpaceMarine	*Squad::getUnit(int N) const
{
	if (N > _unitsInSquad)
		return (NULL);
	else
	{
		t_list	*curUnit = _listSquad;
		for (int i = 0; i < N; i++)
			curUnit = curUnit->nextUnit;
		return (curUnit->data);
	}
}

int				Squad::push(ISpaceMarine *item)
{
	if (!item)
		return (_unitsInSquad);
	if (!_listSquad)
	{
		_listSquad = newElement(item);
		return (_listSquad ? ++_unitsInSquad : 0);
	}
	t_list	*squadUnit = _listSquad;
	while (squadUnit->nextUnit)
	{
		if (squadUnit->data == item)
			return (_unitsInSquad);
		squadUnit = squadUnit->nextUnit;
	}
	if (squadUnit->data == item)
		return (_unitsInSquad);
	squadUnit->nextUnit = newElement(item);
	return (squadUnit->nextUnit ? ++_unitsInSquad : _unitsInSquad);
}

Squad::Squad(const Squad &toCopy)
{
	if (toCopy._unitsInSquad > 0)
	{
		_listSquad = deepCopy(toCopy._listSquad);
		if (_listSquad)
		{
			_unitsInSquad = toCopy._unitsInSquad;
			return ;
		}
	}
	_listSquad = NULL;
	_unitsInSquad = 0;
}

Squad	&Squad::operator=(const Squad &toCopy)
{
	if (this == &toCopy)
		return (*this);
	removeList(_listSquad);
	_listSquad = deepCopy(toCopy._listSquad);
	if (_listSquad)
		_unitsInSquad = toCopy._unitsInSquad;
	else
		_unitsInSquad = 0;
	return (*this);
}

t_list		*newElement(ISpaceMarine *data)
{
	try
	{
		t_list	*newList;
		newList = new t_list;
		newList->data = data;
		newList->nextUnit = NULL;
		return (newList);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

t_list		*deepCopy(t_list *listSquad)
{
	if (!listSquad)
		return (NULL);
	t_list	*newList = newElement((listSquad->data ?\
									listSquad->data->clone() : NULL));
	if (!newList)
		return (NULL);
	t_list	*tmpPtr = newList;
	listSquad = listSquad->nextUnit;
	while (listSquad)
	{
		tmpPtr->nextUnit = newElement((listSquad->data ?\
									listSquad->data->clone() : NULL));
		if (!tmpPtr->nextUnit)
			return (removeList(newList) ?\
					(t_list *)NULL : (t_list *)NULL);
		listSquad = listSquad->nextUnit;
		tmpPtr = tmpPtr->nextUnit;
	}
	return (newList);
}

int			removeList(t_list *listSquad)
{
	try
	{
		t_list	*tmpElement;
		while (listSquad)
		{
			tmpElement = listSquad;
			delete tmpElement->data;
			listSquad = listSquad->nextUnit;
			delete tmpElement;
		}
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}
