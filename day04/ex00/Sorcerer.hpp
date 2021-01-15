/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:01:14 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/11 21:14:45 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer
{
private:
	std::string	_name;
	std::string	_title;
	Sorcerer();
public:
	Sorcerer(const Sorcerer &toCopy);
	Sorcerer(const std::string &name, const std::string &title);
	const std::string	&getName() const;
	const std::string	&getTitle() const;
	void				polymorph(Victim const &v) const;
	Sorcerer &operator=(const Sorcerer &copy);
	virtual ~Sorcerer();

private:
};

std::ostream	&operator<<(std::ostream &o, const Sorcerer &s);

#endif
