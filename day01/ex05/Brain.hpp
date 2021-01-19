#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <sstream>
# include <iostream>

class	Brain
{
	private:
		int		iq_;
	public:
		Brain(int iq);
		Brain();
		const std::string	identify(void) const;
		void				show_iq(void) const;
		void				set_iq(int new_iq);
		~Brain();
};

#endif
