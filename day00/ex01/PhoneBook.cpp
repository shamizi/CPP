/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:27:46 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/19 14:54:40 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{}

Contact::~Contact()
{}

PhoneBook::PhoneBook()
{}

PhoneBook::~PhoneBook()
{}

void	Contact::setFirstname(std::string str)
{
	this->_FirstName = str;
}

std::string	Contact::getFirstname(void) const
{
	return (this->_FirstName);
}

void	Contact::setLastname(std::string str)
{
	this->_LastName = str;
}

std::string	Contact::getLastname(void) const
{
	return (this->_LastName);
}

void	Contact::setNickname(std::string str)
{
	this->_NickName = str;
}

std::string	Contact::getNickname(void) const
{
	return (this->_NickName);
}

void	Contact::setPhonenumber(std::string str)
{
	this->_PhoneNumber = str;
}

std::string	Contact::getPhonenumber(void) const
{
	return (this->_PhoneNumber);
}

void	Contact::setSecret(std::string str)
{
	this->_Secret = str;
}

std::string	Contact::getSecret(void) const
{
	return (this->_Secret);
}

void	PhoneBook::add(int index)
{
	std::string commande;
	std::string ret;

	std::cout << "you're about to add a contact, press ENTER to continue";
	if(getline(std::cin, commande))
	{
		std::cout << "enter first name :" << std::endl;
		std::getline(std::cin, ret);
		this->_Contact[index].setFirstname(ret);
		
		std::cout << "enter last name :" << std::endl;
		std::getline(std::cin, ret);
		this->_Contact[index].setLastname(ret);

		std::cout << "enter nickname :" << std::endl;
		std::getline(std::cin, ret);
		this->_Contact[index].setNickname(ret);

		std::cout << "enter phone number :" << std::endl;
		std::getline(std::cin, ret);
		this->_Contact[index].setPhonenumber(ret);

		std::cout << "enter secret :" << std::endl;
		std::getline(std::cin, ret);
		this->_Contact[index].setSecret(ret);

		if (_Contact[index].getFirstname() == ""|| \
			_Contact[index].getLastname() == ""|| \
			_Contact[index].getNickname() == ""|| \
			_Contact[index].getPhonenumber() == ""|| \
			_Contact[index].getSecret() == "")
		{
			std::cout << "you missed an information. Try Again" << std::endl;
			add(index);
		}
		else
			std::cout << "Adding success !" << std::endl;
	}
}

void	Contact::search(int j)
{
	int i;

	std::cout << "         " << j + 1 << "|";
	i = 10 - _FirstName.size();
	while(i-- > 0)
		std::cout << " ";
	if (_FirstName.size() <= 10)
		std::cout << _FirstName << "|" ;
	else
		std::cout << _FirstName.substr(0, 9) << "." << "|";
	i = 10 - _LastName.size();
	while(i-- > 0)
		std::cout << " ";
	if (_LastName.size() <= 10)
		std::cout << _LastName << "|" ;
	else
		std::cout << _LastName.substr(0, 9) << "." << "|";

	i = 10 - _NickName.size();
	while(i-- > 0)
		std::cout << " ";
	if (_NickName.size() <= 10)
		std::cout << _NickName << std::endl ;
	else
		std::cout << _NickName.substr(0, 9) << "." << std::endl;

}

void	PhoneBook::search(int j)
{
	_Contact[j].search(j);
}

void	Contact::print(void)
{
	std::cout << "First name : " << _FirstName << std::endl;
	std::cout << "Last name : " << _LastName << std::endl;
	std::cout << "Nick name : " << _NickName << std::endl;
	std::cout << "Phone number : " << _PhoneNumber << std::endl;
	std::cout << "Secret : " << _Secret << std::endl;
}

void	PhoneBook::show_index(int j)
{
	std::string commande;
	std::stringstream ss;
	int i;

	getline(std::cin, commande);
	ss << commande;
	ss >> i;
	if (i <= 8 && i >= 1 && i <= j)
		_Contact[i - 1].print();
	else
		std::cout << "Wrong index !" << std::endl;
}

int	main(void)
{
	int 		index = 0;
	int 		i = 0;
	int 		j;
	std::string 	commande;
	PhoneBook	phonebook;
	while(getline(std::cin, commande))
	{
		if (commande == "EXIT")
			exit(0);
		else if (commande == "ADD")
		{
			index = index % 8;
			phonebook.add(index);
			i++;
			index++;
		}
		else if (commande == "SEARCH")
		{
			j = -1;
			while (++j < 8 && j < i)
				phonebook.search(j);
			std::cout << "Index number needed ?" << std::endl;
			phonebook.show_index(j);
		}
	}
	return (0);
}
