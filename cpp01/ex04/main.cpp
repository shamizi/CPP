/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:16:51 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/11 18:05:13 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <istream>
#include <ios>
#include <algorithm>

void	search_and_replace(std::string str, char *file, const std::string s1, const std::string s2)
{
	std::ofstream ofs;
	std::string test;
	int pos = -1;
	int i = 0;

	test += file;
	test += ".replace";

	ofs.open((char *) test.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail())
	{
		std::cout <<"Couldn't create outfile" << std::endl;
		return ;
	}
	while (i < (int)str.size())
	{
		pos = str.find(s1, i);
		if (pos == i && pos!= -1)
		{
			ofs << s2;
			i += (int)s1.size();
		}
		else
		{
			ofs << str[i];
			i++;
		}
	}
	ofs.close();
}

int		main(int argc, char **argv)
{
	std::ifstream ifs;
	std::string str;
	char c;

	if (argc != 4)
	{
		std::cout << "Usage : Filename str1 str2" <<std::endl;
		return (1);
	}
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];

	ifs.open(argv[1], std::ifstream::in);
	if (ifs.fail())
	{
		std::cout <<"couldn't open file" <<std::endl;
		return (1);
	}
	c = ifs.get();
	while (ifs.good())
	{
		str += c;
		c = ifs.get();
	}
	ifs.close();
	search_and_replace(str, argv[1], s1, s2);
	return 0;
}

//string insert ecrit avant la position pos;
//trouver la position de la chaine de caractere souhaiter ? seekg ?
//ofs = filename.replace
//ofs.fail
