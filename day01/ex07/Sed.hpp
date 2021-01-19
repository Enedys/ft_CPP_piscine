#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed
{
	private:
		static std::string find_and_replace_(std::string s, const std::string &find, const std::string &replace);
	public:
		Sed();
		~Sed();
		static void	sed(const std::string &filename, const std::string &find, const std::string &replace);
};

#endif