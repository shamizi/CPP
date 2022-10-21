/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:06:00 by shamizi           #+#    #+#             */
/*   Updated: 2022/10/19 14:42:47 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>

class Contact {
	public :
		Contact();
		~Contact();

		//getter
		std::string getFirstname(void) const;
		std::string getLastname(void) const;
		std::string getNickname(void) const;
		std::string getPhonenumber(void) const;
		std::string getSecret(void) const;

		//setter
		void	setFirstname(std::string str);
		void	setLastname(std::string str);
		void	setNickname(std::string str);
		void	setPhonenumber(std::string str);
		void	setSecret(std::string str);

		//autre
		void	search(int j);
		void	print(void);
	private :
		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _Secret;
		//int _index;
};

class PhoneBook {
	public :
		PhoneBook();
		~PhoneBook();
	/*	//getter
		Contact	getContact(int index) const;
		//setter
		void setContact(Contact contacts);*/
		void	add(int index);
		void	show_index(int j);
		void 	search(int j);
	private :
	//	int	_index;
		Contact _Contact[8];

};
#endif
