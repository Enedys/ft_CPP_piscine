#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->amount = 0;
}

Phonebook::~Phonebook()
{
}

void	Phonebook::add_new_contact(void)
{
	if (this->amount == 8)
		std::cout << "Contact list is full!\n";
	else
		if (this->contact_list[this->amount].create_contact() == true)
			this->amount++;
}

void	Phonebook::show_contact_info(void)
{
	std::cout << "     Index|" << "First Name|" << " Last Name|" << "  Nickname|" << std::endl;
	for(int i = 0; i < this->amount; i++)
		this->contact_list[i].display_descr(i);
}

void	Phonebook::find_contact(void)
{
	int	cont_num;

	if (this->amount == 0)
	{
		std::cout << "-- Contact list is empty!\n";
		return ;
	}
	this->show_contact_info();
	while (true)
	{
		std::cout << "Choose contact number (0 for exit): ";
		std::cin >> cont_num;
		if (std::cin.fail() || cont_num < 0 || cont_num > this->amount)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "-- Invalid index.\n";
			continue ;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (cont_num)
			this->contact_list[(int)cont_num - 1].display_contact();
		return ;
	}
}