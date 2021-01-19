#include "Phonebook.hpp"

Phonebook::Phonebook() : _amount(0)
{
}

Phonebook::~Phonebook()
{
}

void	Phonebook::add_new_contact(void)
{
	if (this->_amount == 8)
		std::cout << " ! Contact list is full !\n";
	else
		if (this->_contact_list[this->_amount].create_contact() == true)
			this->_amount++;
}

void	Phonebook::show_contact_info(void) const
{
	std::cout << "     Index|" << "First Name|" << " Last Name|" << "  Nickname|" << std::endl;
	for(int i = 0; i < this->_amount; i++)
		this->_contact_list[i].display_descr(i);
}

void	Phonebook::find_contact(void) const
{
	int	cont_num;

	if (this->_amount == 0)
	{
		std::cout << "! Contact list is empty !\n";
		return ;
	}
	this->show_contact_info();
	while (true)
	{
		std::cout << "Choose contact number (or 0 for exit): ";
		std::cin >> cont_num;
		if (std::cin.fail() || cont_num < 0 || cont_num > this->_amount)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "! Invalid index !\n";
			continue ;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (cont_num)
			this->_contact_list[(int)cont_num - 1].display_contact();
		return ;
	}
}