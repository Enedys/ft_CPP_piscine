/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillum <kwillum@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 09:49:43 by kwillum           #+#    #+#             */
/*   Updated: 2021/01/20 16:37:52 by kwillum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <cmath>
# include <limits>

# define CHAR	1
# define INT	2
# define FLOAT	3
# define DOUBLE 4
# define DNAN	5
# define FNAN	6
# define FINF	7
# define DINF	8
# define toType(number, type) static_cast<type>(number)

int		isStrType(int type)
{
	if (type == DNAN || type == FNAN || type == FINF || type == DINF)
		return (1);
	return (0);
}

struct		s_salues
{
	int		valInt;
	double	valDouble;
	float	valFloat;
	char	valChar;
	int		error;
} typedef	t_values;

int isStringNumbers(std::string &s)
{
	if (s == "-inff" || s == "+inff")
		return (FINF);
	else if (s == "nanf")
		return (FNAN);
	if (s == "-inf" || s == "+inf")
		return (DINF);
	else if( s == "nan")
		return (DNAN);
	else
		return (0);
}

int	returnVlueType(int isDot, int isLatter)
{
	if (isDot && isLatter)
		return (FLOAT);
	else if (isDot)
		return (DOUBLE);
	else if (isLatter)
		return (CHAR);
	else
		return (INT);	
}

int	isValidString(std::string &s)
{
	int isStr  = isStringNumbers(s);
	if (isStr)
		return (isStr);
	int	dotNum = 0;
	int	latterNum = 0;
	int j = 0;
	if (s.at(0) == '-' || s.at(0) == '+')
		j++;
	for (; j < s.length(); j++)
	{
		if (s.at(j) == 'f' && !latterNum && dotNum && s.length() == j + 1) 
			return (FLOAT);
		if (!std::isdigit(s.at(j)))
		{
			if (s.at(j) == '.' && !dotNum)
			{
				latterNum++;
				dotNum++;
				continue ;
			}
			if (latterNum++ || j)
				return (0);
		}
	}
	return (returnVlueType(dotNum, latterNum));
}

int	processStringNumbers(std::string &s, int type)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (type == FINF || type == FNAN)
	{
		std::cout << "float: " << s << std::endl;
		s.pop_back();
		std::cout << "double: " << s << std::endl;
		return (0);
	}
	std::cout << "float: " << s << "f\n";
	std::cout << "double: " << s << std::endl;
	return (0);
}

void processIntNumber(std::stringstream &ss, t_values &values)
{
	ss >> values.valInt;
	if (values.valInt > CHAR_MAX || values.valInt < CHAR_MIN)
		values.error |= 1;
	else
		values.valChar = toType(values.valInt, char);
	values.valFloat = toType(values.valInt, float);
	values.valDouble = toType(values.valInt, double);
}

void processFloatNumber(std::stringstream &ss, t_values &values)
{
	ss << ".f";
	ss >> values.valFloat;
	if (values.valFloat > CHAR_MAX || values.valFloat < CHAR_MIN)
		values.error |= 1;
	else
		values.valChar = toType(values.valFloat, char);
	if (values.valFloat > INT_MAX || values.valFloat < INT_MIN)
		values.error |= 2;
	else
		values.valInt = toType(values.valFloat, int);
	values.valDouble = toType(values.valFloat, double);
}

void processDoubleNumber(std::stringstream &ss, t_values &values)
{
	ss >> values.valDouble;
	if (values.valDouble > CHAR_MAX || values.valDouble < CHAR_MIN)
		values.error |= 1;
	else
		values.valChar = toType(values.valDouble, char);
	if (values.valDouble > INT_MAX || values.valDouble < INT_MIN)
		values.error |= 2;
	else
		values.valInt = toType(values.valDouble, int);
	values.valFloat = toType(values.valDouble, float);
}

void processCharNumber(std::stringstream &ss, t_values &values)
{
	ss >> values.valChar;
	values.valInt = toType(values.valChar, int);
	values.valFloat = toType(values.valChar, float);
	values.valDouble = toType(values.valChar, double);
}

void printCastedValues(t_values &values, int type)
{
	std::cout << "char: ";
	if (std::isprint(values.valChar))
		 std::cout << '\'' << values.valChar << '\'' << std::endl;
	else
		std::cout << (values.error & 1 ? "impossible" : "Non displayable") << std::endl;
	std::cout << "int: ";
	if (values.error & 2)
		std::cout << "impossible" << std::endl;
	else
		std::cout << values.valInt << std::endl;
	
	std::cout << "float: ";
	float	intPart = 0;
	float	fractPart = modf(values.valFloat, &intPart);
	float	floatPrec = std::numeric_limits<float>::digits10 + 1;
	std::cout << std::setprecision(floatPrec) << values.valFloat;
	if (((type == INT || type == CHAR) && std::abs(values.valFloat) < \
			std::pow(10, floatPrec)) || (intPart == values.valFloat))
		std::cout<< ".0f";
	else if (fractPart != 0)
		std::cout << "f";
	else if (std::abs(values.valFloat) > std::pow(10,std::numeric_limits<float>::digits10))
		std::cout << "f";
	else
		std::cout<< "f";
	std::cout << std::endl;

	std::cout << "double: ";
	double	intDPart = 0;
	double	fractDPart = modf(values.valDouble, &intDPart);
	float	doublePrec = std::numeric_limits<double>::digits10 + 1;
	std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1) << values.valDouble;
	if (((type == INT || type == CHAR) && std::abs(values.valDouble) < std::pow(10, doublePrec)) || intDPart == values.valDouble)
		std::cout<< ".0";
	std::cout << std::endl;
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
	std::stringstream	ss;
	ss << s;
	t_values	retValues;
	std::memset(&retValues, 0, sizeof(t_values));
	if (isStrType(type))
		return (processStringNumbers(s, type));
	if (type == INT)
		processIntNumber(ss, retValues);
	else if (type == FLOAT)
		processFloatNumber(ss, retValues);
	else if (type == DOUBLE)
		processDoubleNumber(ss, retValues);
	else
		processCharNumber(ss, retValues);
	printCastedValues(retValues, type);
	return (0);
}