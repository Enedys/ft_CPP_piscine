#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		~Phonebook();

		void	find_contact(void);
		void	add_new_contact(void);
		void	show_contact_info(void);

	private:
		Contact	contact_list[8];
		int		amount;
};

# endif