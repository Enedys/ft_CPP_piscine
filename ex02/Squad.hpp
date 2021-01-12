/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:42:22 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/12 16:54:17 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP
# include <iostream>
# include <string>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

struct		s_list
{
	ISpaceMarine	*data;
	struct s_list	*nextUnit;
} typedef	t_list;

class Squad : public ISquad
{
private:
	int			_unitsInSquad;
	t_list		*_listSquad;
public:
	Squad();
	Squad(const Squad &toCopy);
	virtual int				getCount() const;
	virtual ISpaceMarine	*getUnit(int) const;
	virtual int				push(ISpaceMarine *);
	Squad &operator=(const Squad &toCopy);
	virtual ~Squad();
};

t_list		*deepCopy(t_list *listSquad);
int			removeList(t_list *listSquad);
t_list		*newElement(ISpaceMarine *data);


#endif
