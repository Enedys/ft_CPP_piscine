#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

# define FIELDS_NUM 11

class Contact
{
	public:
		Contact();
		~Contact();

		bool				create_contact(void);
		void				display_descr(int index);
		void				display_contact(void);

	private:
		static std::string	fields_name[11];
		std::string			fields[11];
};

# endif
