#include "Contact.hpp"

std::string Contact::fields_name[11] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Login",
	"Address",
	"E-mail",
	"Phone",
	"Birthday",
	"Favorite Meal",
	"Underwear Color",
	"Darkest Secret"
};

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool	Contact::create_contact(void)
{
	int	len = 0;

	for(int i = 0; i < FIELDS_NUM; i++)
	{
		std::cout << this->fields_name[i] << ": ";
		std::getline(std::cin, this->fields[i]);
		len += this->fields[i].length();
	}
	if (len > 0)
		return (true);
	std::cout << "-- Error! Empty contact.\n";
	return (false);
}

void	Contact::display_contact(void)
{
	for(int i = 0; i < FIELDS_NUM; i++)
		std::cout << this->fields_name[i] << ": " << this->fields[i] << std::endl;
}

void	Contact::display_descr(int index)
{
	std::cout << std::setw(10) << std::right << index + 1 << "|";
	for(int i = 0; i < 3; i++)
	{
		if (this->fields[i].length() <= 10)
			std::cout << std::setw(10) << this->fields[i];
		else
			std::cout << std::setw(9) << this->fields[i].substr(0, 9) << ".";
		std::cout << "|";
	}
	std::cout << std::endl;
}
