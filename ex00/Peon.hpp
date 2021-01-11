/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:48:30 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 21:14:15 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

class Peon : public Victim
{
private:
	Peon();
protected:
public:
	Peon(const std::string &name);
	Peon(const Peon &toCopy);
	virtual void	getPolymorphed() const;
	Peon &operator=(const Peon &toCopy);
	virtual ~Peon();
};

#endif
