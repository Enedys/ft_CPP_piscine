/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:27:36 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 21:14:31 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>
# include <string>

class Victim
{
private:
	Victim();
protected:
	std::string	_name;
	void		_copy(const Victim &v);
public:
	Victim(const Victim &toCopy);
	Victim(const std::string &name);
	const std::string	&getName() const;
	virtual void		getPolymorphed() const;
	Victim &operator=(const Victim &toCopy);
	virtual ~Victim();
};

std::ostream &operator<<(std::ostream &o, const Victim &v);

#endif
