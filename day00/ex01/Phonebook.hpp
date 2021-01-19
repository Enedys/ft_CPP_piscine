#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <limits>

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();

		void	find_contact(void) const;
		void	add_new_contact(void);
		void	show_contact_info(void) const;

	private:
		Contact	_contact_list[8];
		int		_amount;
};

# endif