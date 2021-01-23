/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:49:43 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/23 20:41:34 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <iomanip>
# include <cctype>
# include <cfloat>
# include <limits>

# define CHAR	1
# define INT	2
# define FLOAT	3
# define DOUBLE 4
# define DNAN	5
# define FNAN	6
# define FINF	7
# define DINF	8

int			isStringNumbers(std::string &s)
{
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return (FLOAT);
	if (s == "-inf" || s == "+inf" || s == "nan")
		return (DOUBLE);
	else
		return (0);
}

int			returnVlueType(int isDot, int isLat)
{
	if (isDot)
		return (DOUBLE);
	else if (isLat)
		return (CHAR);
	else
		return (INT);	
}

int			isValidString(std::string &s)
{
	int isStr  = isStringNumbers(s);
	if (isStr)
		return (isStr);
	int	dotNum = 0;
	int	latterNum = 0;
	size_t j = 0;
	if (s.length() == 3 && s.at(0) == '\'' && s.at('\''))
		return (CHAR);
	if (s.at(0) == '-' || s.at(0) == '+')
		j++;
	for (; j < s.length(); j++)
	{
		if (s.at(j) == 'f' && dotNum && !latterNum && s.length() == j + 1) 
			return (FLOAT);
		if (!std::isdigit(s.at(j)))
		{
			if (!j && s.length() == 1)
				return (CHAR);
			if (s.at(j) == '.' && !dotNum && !latterNum)
			{
				dotNum++;
				continue ;
			}
			if (latterNum++ || j)
				return (0);
		}
	}
	return (returnVlueType(dotNum, latterNum));
}

void		displayCasts(long double ldNum)
{
	std::cout << "char: ";
	if (ldNum <= CHAR_MAX && ldNum >= CHAR_MIN)
	{
		if(std::isprint(static_cast<char>(ldNum)))
			std::cout << '\'' << static_cast<char>(ldNum) << '\'' << std::endl;
		else if (!std::isprint(static_cast<char>(ldNum)))
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (ldNum <= INT_MAX && ldNum >= INT_MIN)
			std::cout << static_cast<int>(ldNum) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if ((std::abs(ldNum) <= FLT_MAX && std::abs(ldNum) >= FLT_MIN)\
		|| ldNum == static_cast<float>(0) || ldNum != ldNum\
		|| ldNum == static_cast<float>(1.0 / 0.0)\
		|| ldNum == static_cast<float>(-1.0 / 0.0))
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(ldNum) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "double: ";
	if ((std::abs(ldNum) <= DBL_MAX && std::abs(ldNum) >= DBL_MIN)\
		|| ldNum == static_cast<double>(0) || ldNum != ldNum\
		|| ldNum == static_cast<double>(1.0 / 0.0)\
		|| ldNum == static_cast<double>(-1.0 / 0.0))
		std::cout << std::fixed << static_cast<double>(ldNum) << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

long double	createLongDoubleBuf(std::string &s, int type)
{
	std::stringstream	ss;
	long double	ldNum;
	if (type == FLOAT)
		s = s.substr(0, s.length() - 1);
	if (type != CHAR)
	{
		ss << s;
		ss >> ldNum;
	}
	else if (s.length() == 1)
		ldNum = static_cast<int>(s.at(0));
	else
		ldNum = static_cast<int>(s.at(1));
	return (ldNum);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid numbers of argumet;\n";
		return (1);
	}
	std::string	s(argv[1]);
	if (!s.length())
	{
		std::cout << "Error: Empty line are passed;\n";
		return (1);
	}
	int type = 0;
	if (!(type = isValidString(s)))
	{
		std::cout << "Error: Not a valid string;\n";
	 	return (1);
	}
	long double ldNum = createLongDoubleBuf(s, type);
	// std::cout << "TYPE: " << type << std::endl;
	displayCasts(ldNum);
	return (0);
}