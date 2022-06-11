/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:37:17 by shamizi           #+#    #+#             */
/*   Updated: 2022/06/09 17:16:57 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRIAN";
	std::string* stringPTR = &str;
	std::string& stringREF = str; //reference ici la reference pointe sur la variable. On ne pourra plus changer cette ref
	
	std::cout << "Memory adress str: " << &str << std::endl;
	std::cout << "Memory adress stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory adress stringREF: " << &stringREF << std::endl;
	str = "bonjour";
	std::cout << "Value str: " << str << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value stringREF: " << stringREF << std::endl;
}

/*
   les reference :
   un pointeur constant jamais null et toujour dereferencer

   passage de parametre par reference
   
   retour par reference

   pointeur utile si le truc risaue de changer
   si sa ne change jamais utiliser une reference est plus pratique
   */
