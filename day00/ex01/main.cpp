/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:47:14 by Kwillum           #+#    #+#             */
/*   Updated: 2021/01/08 00:33:48 by Kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.hpp"

int	main()
{
	std::string	cmd;
	Phonebook	book;

	std::cout << "Hello. It's a simple phonebook.\nAvailible commands: ADD, SEARCH, EXIT\n";
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			book.add_new_contact();
		else if (cmd == "SEARCH")
			book.find_contact();
		else if (cmd == "EXIT")
		{
			std::cout << "Close.\n";
			return (0);
		}
		else
			std::cout << "! Invalid command !\n";
	}
	return (0);
}
