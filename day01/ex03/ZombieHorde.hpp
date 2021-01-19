#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <string>
# include <iostream>
# include <cstdlib>		// rand(), srand()
# include <ctime>		// time()
# include "Zombie.hpp"

# define NAMES_NUM 7

class	ZombieHorde
{
	private:
		int					zombies_number_;
		Zombie				*zombies_army_;
		int					getRandomNumber_(int min, int max) const;
		static std::string	names_list[NAMES_NUM];
		ZombieHorde();
	public:
		ZombieHorde(int N);
		~ZombieHorde();
		void	announce(void) const;
};

#endif