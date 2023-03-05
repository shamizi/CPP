/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:57:17 by shamizi           #+#    #+#             */
/*   Updated: 2023/01/28 13:27:01 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(std::string str)
{
	this->_str = str;
}

Convert::Convert(Convert const &src)
{
	*this = src;
}

Convert	& Convert::operator=(Convert const & rhs)
{
	this->_str = rhs._str;
	return (*this);
}

Convert::~Convert()
{}

std::string	Convert::getStr()
{
	return (this->_str);
}

bool	Convert::isint(std::string str)
{
	int i = 0;
	const char *cstr = str.c_str();

	if (cstr[i] == '+' || cstr[i] == '-')
		i++;
	while (cstr[i])
	{
		if (isdigit(cstr[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

bool	Convert::ischar(std::string str)
{
	if (str.size() != 1)
		return false;
	if (!isprint(str.c_str()[0]))
	{
		std::cout << "Non-printable character" << std::endl;
		return false;
	}
	return true;
}

bool	Convert::isfloat(std::string str)
{
	int point = 0;
	size_t i = 0;
	if (str.c_str()[str.size() - 1] != 'f')
		return false;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;

	if (str.c_str()[i] == '+' || str.c_str()[i] == '-')
		i++;
	while (i < str.size())
	{
		if (str.c_str()[i] == '.' && isdigit(str.c_str()[i + 1]))
		{
			i++;
			point++;
		}
		else if (str.c_str()[i] == 'f' && str.c_str()[i + 1] != '\0')
			return false;
		else
			i++;

	}
	if (point == 1)
		return true;
	else
		return false;
}

bool	Convert::isdouble(std::string str)
{
	int point = 0;
	size_t i = 0;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	if (str.c_str()[i] == '+' || str.c_str()[i] == '-')
		i++;
	while (i < str.size())
	{
		if (str.c_str()[i] == '.' && isdigit(str.c_str()[i + 1]))
		{
			i++;
			point++;
		}
		else if (isdigit(str.c_str()[i]))
			i++;
		else
			return false;

	}
	if (point == 1)
		return true;
	else
		return false;

}

void	Convert::Cconvert()
{
	std::cout << "char: ";
	if (_str == "nan" || _str == "+inf" || _str == "-inf" || _str == "nanf" || _str == "-inff" || _str == "+inff")
		std::cout << "impossible" << std::endl;
	else if (_str.size() == 1 && !isdigit(_str.c_str()[0]))
	{
		if (isprint(_str.c_str()[0]))
			std::cout << _str << std::endl;
		else
			std::cout << "non printable" << std::endl;
	}
	else
	{
		double result;
		char *pEnd = NULL;
		result = strtod(_str.c_str(), &pEnd);
		if ((errno == ERANGE && (result == -HUGE_VAL || result == HUGE_VAL)) || result > 255 || result < 0)
			std::cout << "impossible" << std::endl;
		else if (!isprint(static_cast<char>(result)))
			std::cout << "non printable" << std::endl;
		else
			std::cout << static_cast<char>(result) << std::endl;
	}
}

void	Convert::Iconvert()
{
	std::cout << "int: ";
	if (_str == "nan" || _str == "+inf" || _str == "-inf" || _str == "nanf" || _str == "-inff" || _str == "+inff")
		std::cout << "impossible" << std::endl;
	else if (_str.size() == 1 && !isdigit(_str.c_str()[0]))
		std::cout << static_cast<int>(_str.c_str()[0]) << std::endl;
	else
	{
		double result;
		char *pEnd = NULL;
		result = strtod(_str.c_str(), &pEnd);
		if ((errno == ERANGE && (result == -HUGE_VAL || result == HUGE_VAL)) || result > 2147483647  || result < -2147483648)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(result) << std::endl;
	}
}

void	Convert::Fconvert()
{
	std::cout << "float: ";
	if (_str == "nan" || _str == "+inf" || _str == "-inf")
		std::cout << this->_str.append("f") << std::endl;
	else if (_str == "nanf" || _str == "+inff" || _str == "-inff")
		std::cout << _str << std::endl;
	else if (_str.size() == 1 && !isdigit(_str.c_str()[0]))
		std::cout << std::setprecision(1) << std::fixed << static_cast<float>(_str.c_str()[0]) << "f" << std::endl;
	else
	{
		double result;
		char *pEnd = NULL;
		result = strtod(_str.c_str(), &pEnd);
		if ((errno == ERANGE && (result == -HUGE_VAL || result == HUGE_VAL)) && (result > FLT_MAX  || result < FLT_MIN))
			std::cout << "impossible" << std::endl;
		else
			std::cout << std::setprecision(1) << std::fixed << static_cast<float>(result) << "f" << std::endl;
	}
}

void	Convert::Dconvert()
{
	std::cout << "double: ";
	if (_str == "nan" || _str == "+inf" || _str == "-inf")
		std::cout << _str << std::endl;
	else if (_str == "nanf" || _str == "+inff" || _str == "-inff")
		std::cout << _str.erase(_str.size() - 1, 1) << std::endl;
	else if (_str.size() == 1 && !isdigit(_str.c_str()[0]))
		std::cout << std::setprecision(1) << std::fixed << static_cast<double>(_str.c_str()[0]) << std::endl;
	else
	{
		double result;
		char *pEnd = NULL;
		result = strtod(_str.c_str(), &pEnd);
		if ((errno == ERANGE && (result == -HUGE_VAL || result == HUGE_VAL)) && (result > DBL_MAX  || result < DBL_MIN))
			std::cout << "impossible" << std::endl;
		else
			std::cout << std::setprecision(1) << std::fixed << static_cast<float>(result) << std::endl;
	}
}

int	Convert::checktype()
{
	if (isdouble(getStr()) == false && isint(getStr()) == false && ischar(getStr()) == false && isfloat(getStr()) == false)
		return 0;
	else
		return 1;
}
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : \"One argument\"\n";
		return (0);
	}
	Convert a(argv[1]);
	if (a.checktype())
	{
		a.Cconvert();
		a.Iconvert();
		a.Fconvert();
		a.Dconvert();
	}
	else
		std::cout << "Use one of those type : INT / CHAR / FLOAT / DOUBLE" << std::endl;
	return 0;
}
