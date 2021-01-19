#include "Sed.hpp"

std::string	Sed::find_and_replace_
(std::string s, const std::string &find, const std::string &replace)
{
	unsigned long	pos = 0;
	while ((pos = s.find(find, pos)) != std::string::npos)
	{
		s.replace(pos, find.length(), replace);
		pos += replace.length();
	}
	return (s);
}

void		Sed::sed
(const std::string &filename, const std::string &find, const std::string &replace)
{
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cout << "Can`t open input file\n";
		return ;
	}
	std::ofstream	outputFile;
	outputFile.open((filename + ".replace").c_str(), std::ios::trunc);
	if (!outputFile.is_open())
	{
		inputFile.close();
		std::cout << "Can`t open output file\n";
		return ;
	}
	std::string	readline;
	while (std::getline(inputFile, readline))
	{
		outputFile << find_and_replace_(readline, find, replace);
		if (!inputFile.eof())
			outputFile << std::endl;
	}
	outputFile.close();
	inputFile.close();
}

Sed::Sed()
{
}

Sed::~Sed()
{
}