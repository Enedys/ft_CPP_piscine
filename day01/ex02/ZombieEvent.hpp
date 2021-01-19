#pragma once
#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>		// time()


# define NAMES_NUM 7

class	ZombieEvent
{
	private:
		std::string			type_;
		static std::string	names_list_[NAMES_NUM];
		int					getRandomNumber_(int min, int max) const;
	public:
		ZombieEvent();
		~ZombieEvent();
		void	setZombieType(const std::string &type);
		Zombie	*newZombie(std::string name);
		Zombie	*randomChump(void);
};

#endif