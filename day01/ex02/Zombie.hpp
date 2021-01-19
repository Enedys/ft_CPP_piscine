#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie
{
	private:
		std::string	name_;
		std::string	type_;
		Zombie();
	public:
		Zombie(const std::string &name, const std::string &type);
		~Zombie();
		void	set_name(const std::string &new_name);
		void	announce(void) const;
};

#endif