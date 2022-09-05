/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:08:37 by shamizi           #+#    #+#             */
/*   Updated: 2022/09/02 12:17:05 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>

void	contact::add(int index)
{
	std::string commande;

	std::cout << "you're about to add a contact, press a ENTER to continue";
	if (getline(std::cin, commande))
	{
		std::cout << "enter first_name :" << std::endl;
		std::getline(std::cin, _first_name);
		_index = index + 1;
		std::cout << "enter last_name :" << std::endl;
		std::getline(std::cin, _last_name);
		std::cout << "enter nickname :" << std::endl;
		std::getline(std::cin, _nickname);
		std::cout << "enter phone number :" << std::endl;
		std::getline(std::cin, _phone_number);
		std::cout << "enter secret :" << std::endl;
		std::getline(std::cin, _secret);
		if (_secret == "" || _phone_number == "" || _nickname == "" || _last_name == "" || _first_name == "")
		{
			std::cout << "you miss an information ! Try again" << std::endl;
			add(index);
		}
		else
			std::cout << "Adding success !" << std::endl;
	}
	/*	std::cout << _first_name << std::endl;
		std::cout << _last_name << std::endl;
		std::cout << _nickname << std::endl;
		std::cout << _phone_number << std::endl;
		std::cout << _secret << std::endl;*/
}

void	contact::search(void)
{
	int i;

	std::cout << "         " << _index << "|";
	i = 10 - _first_name.size();
	while(i-- > 0)
		std::cout << " ";
	if (_first_name.size() <= 10)
		std::cout << _first_name << "|" ;
	else
		std::cout << _first_name.substr(0, 9) << "." << "|";
	i = 10 - _last_name.size();
	while(i-- > 0)
		std::cout << " ";
	if (_last_name.size() <= 10)
		std::cout << _last_name << "|" ;
	else
		std::cout << _last_name.substr(0, 9) << "." << "|";

	i = 10 - _nickname.size();
	while(i-- > 0)
		std::cout << " ";
	if (_nickname.size() <= 10)
		std::cout << _nickname << std::endl ;
	else
		std::cout << _nickname.substr(0, 9) << "." << std::endl;
}

void	contact::print(void)
{
	std::cout << "first name : " << _first_name << std::endl;
	std::cout << "last name : " << _last_name << std::endl;
	std::cout << "nick name : " << _nickname << std::endl;
	std::cout << "phone number : " << _phone_number << std::endl;
	std::cout << "secret : " << _secret << std::endl;
}

void	show_index(contact page[8], int t)
{
	std::string commande;
	std::stringstream ss;
	int i;

	getline(std::cin, commande);
	ss << commande;
	ss >> i;
	if (i <= 8 && i >= 1  && i <= t)
		page[i - 1].print();
	else
		std::cout << "l'index demandé n'est pas attribué, relancez search avec un bon index" << std::endl;
}

int	main(void)
{
	int index;
	int i;
	int j;
	std::string commande;
	contact page[8];

	index = 0;
	i = 0;
	while(getline(std::cin, commande))
	{
		if (commande == "exit")
			exit(0);
		else if (commande == "add")
		{
			index = index % 8;
			page[index].add(index);
			index++;
			i++;
		}
		else if (commande == "search")
		{
			j = -1;
			while(++j < 8 && j < i)
				page[j % 8].search();
			std::cout << "numéro d'index souhaiter : " << std::endl;
			show_index(page, i);
		}
		std::cout << "___________________________________________________________________" << std::endl;
	}
	return (0);
}
