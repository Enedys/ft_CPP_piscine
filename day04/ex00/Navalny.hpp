/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Navalny.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:43:56 by Kwillum           #+#    #+#             */
/*   Updated: 2021/01/22 01:44:46 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAVALNY_HPP
# define NAVALNY_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

class Navalny : public Victim
{
private:
	Navalny();
protected:
public:
	Navalny(const std::string &name);
	Navalny(const Navalny &toCopy);
	virtual void	getPolymorphed() const;
	Navalny &operator=(const Navalny &toCopy);
	virtual ~Navalny();
};

#endif
